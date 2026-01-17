/***************************************************************
 * Project:       render-engine
 * File:          Graphics_Factory.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-11-28
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
#ifndef RENDER_ENGINE_GRAPHICS_FACTORY_H
#define RENDER_ENGINE_GRAPHICS_FACTORY_H

#include <memory>

#include "infra/ast/Event_Collector.h"
#include "infra/event/Event_Collector.h"
#include "rb/ast/RB_Config.h"
#include "rb/Renderer.h"

namespace core {
    class Graphics_Factory{
        public:

        static Graphics_Factory& instance();

        std::shared_ptr<rb::Renderer> make_Renderer(const rb::ast::RB_Config &info);

        std::unique_ptr<infra::event::Event_Collector> make_Event_Collector(const infra::ast::Event_Collector &info);

    private:
        Graphics_Factory();

        static void Register(
            std::unordered_map<
                rb::ast::RB_Type,
                std::shared_ptr<rb::Renderer> (Graphics_Factory::*)(const rb::ast::RB_Config&)
            > &outMap
        );

        std::unique_ptr<infra::event::Event_Collector> event_collector_;

        std::shared_ptr<rb::Renderer> make_SFML_Renderer(const rb::ast::RB_Config& info);
    };
}

#endif //RENDER_ENGINE_GRAPHICS_FACTORY_H