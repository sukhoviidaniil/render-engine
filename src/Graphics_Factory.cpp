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

namespace core {
    std::shared_ptr<rb::Renderer> Graphics_Factory::make_View(const rb::ast::RB_Config &info, const std::string &path) {
        std::unordered_map<rb::ast::RB_Type, std::shared_ptr<rb::Renderer>(*)(const rb::ast::RB_Config&, const std::string&)> map;
        Register(map);
        rb::ast::RB_Type type = info.type;
        auto it = map.find(type);
        if (it != map.end()) {
            return it->second(info, path);
        }
        throw std::runtime_error("Unknown rb type: " + to_string(type));
    }

    void Graphics_Factory::Register(
        std::unordered_map<rb::ast::RB_Type, std::shared_ptr<rb::Renderer>(*)(const rb::ast::RB_Config&, const std::string&)> &outMap
        ) {
        outMap[rb::ast::RB_Type::SFML] = &Graphics_Factory::SFML_Renderer;

    }

    std::shared_ptr<rb::Renderer> Graphics_Factory::SFML_Renderer(const rb::ast::RB_Config& info, const std::string& path) {
        auto view = std::make_shared<SFML_Renderer>(info, path);
        event_collector_ = std::make_unique<SFML_Event_Collector>(*view);
        return view;
    }
}

