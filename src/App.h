/***************************************************************
 * Project:       Render_Engine
 * File:          App.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-17
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Render_Engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_APP_H
#define RENDER_ENGINE_APP_H
#include "infra/ast/Event_Collector.h"
#include "infra/event/Event_Collector.h"
#include "infra/event/Observer.h"
#include "rb/Renderer.h"
#include "rb/ast/RB_Config.h"
#include "rb/layout_engine/elements/UIElement.h"

namespace core {
    class App : public infra::event::Observer {
    public:
        ~App() override;
        App(
            const std::shared_ptr<infra::event::Event_Bus>& eventbus,
            const rb::ast::RB_Config& rb_config,
            const infra::ast::Event_Collector & ecoll_config,
            const std::string& ui_file
            );

        void run();
    private:

        bool running_ = true;

        std::shared_ptr<rb::Renderer> renderer_;
        std::unique_ptr<infra::event::Event_Collector> event_collector_;

        std::shared_ptr<infra::event::Event_Bus> g_eventbus_;

        std::unique_ptr<rb::ui::UIElement> root_;
    };
}



#endif //RENDER_ENGINE_APP_H