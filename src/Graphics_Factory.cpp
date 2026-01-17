/***************************************************************
 * Project:       render-engine
 * File:          Graphics_Factory.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-02
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of render-engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "Graphics_Factory.h"

#include "infra/diagnostics/Logger.h"
#include "my_sfml/SFML_Event_Collector.h"
#include "my_sfml/SFML_Font_AssetLoader.h"
#include "my_sfml/SFML_Renderer.h"
#include "rb/registry/AssetHandle.h"
#include "rb/registry/AssetRegistry.h"

namespace core {
    Graphics_Factory & Graphics_Factory::instance() {
        static Graphics_Factory inst;
        return inst;
    }

    std::shared_ptr<rb::Renderer> Graphics_Factory::make_Renderer(const rb::ast::RB_Config &info) {
        std::unordered_map<rb::ast::RB_Type, std::shared_ptr<rb::Renderer>(Graphics_Factory::*)(const rb::ast::RB_Config&)> map;
        Register(map);
        const rb::ast::RB_Type type = info.type;
        auto it = map.find(type);
        if (it != map.end()) {
            return (this->*(it->second))(info);
        }
        throw std::runtime_error("Unknown rb type: " + to_string(type));
    }

    std::unique_ptr<infra::event::Event_Collector> Graphics_Factory::make_Event_Collector(
        const infra::ast::Event_Collector &info) {
        if (event_collector_ != nullptr) {
            return std::move(event_collector_);
        }
        /* If there is no event_collector_ at this point, then you need to have a system that will create it.
         * Since the implementation assumes that SFML will be used, this means that the collector was already created when the Renderer was created.
         * And since we cannot assume the data required to create another collector, all we can do is throw an error - it is not possible to create a collector.
         */
        std::string err = "Event collector not initialized";
        LOG(err);
        throw std::runtime_error("Event collector not initialized");
    }

    Graphics_Factory::Graphics_Factory() = default;

    void Graphics_Factory::Register(
        std::unordered_map<rb::ast::RB_Type, std::shared_ptr<rb::Renderer>(Graphics_Factory::*)(const rb::ast::RB_Config&)> &outMap
        ) {
        outMap[rb::ast::RB_Type::SFML] = &Graphics_Factory::make_SFML_Renderer;

    }

    std::shared_ptr<rb::Renderer> Graphics_Factory::make_SFML_Renderer(const rb::ast::RB_Config& info) {
        auto rb = std::make_shared<rb::sfml::SFML_Renderer>(info);
        // Since events in SFML come from the window, we create an event collector here.
        event_collector_ = std::make_unique<rb::sfml::SFML_Event_Collector>(*rb);

        // Filling the Registry with the correct asset loaders
        rb::rgst::AssetRegistry::instance().register_loader(
            rb::asset::AssetType::Font,
            std::make_unique<rb::sfml::SFML_Font_AssetLoader>()
            );
        return rb;
    }
}

