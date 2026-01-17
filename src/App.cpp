/***************************************************************
 * Project:       Render_Engine
 * File:          App.cpp
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
#include "App.h"

#include "Graphics_Factory.h"
#include "infra/diagnostics/Logger.h"
#include "infra/event/events/window.hpp"
#include "infra/internal/Delta_Timer.h"
#include "rb/layout_engine/Parser.h"
#include "rb/layout_engine/Tokenizer.h"
#include "rb/layout_engine/UIFactory.h"

namespace core {
    App::~App() = default;

    App::App(
        const std::shared_ptr<infra::event::Event_Bus> &eventbus,
        const rb::ast::RB_Config &rb_config,
        const infra::ast::Event_Collector & ecoll_config,
        const std::string& ui_file)
    :g_eventbus_(eventbus) {

        // Be sure to track at least one event that will complete the cycle.
        track(
            eventbus->subscribe<infra::event::window::Window_Closed>(
                [this](const infra::event::window::Window_Closed&) {
                    running_ = false;
                }
            )
        );

        // Creating a renderer and event collector
        renderer_ = Graphics_Factory::instance().make_Renderer(rb_config);
        event_collector_ = Graphics_Factory::instance().make_Event_Collector(ecoll_config);

        // -- The next part is related to the UI. --

        // Read and tokenize UI data
        std::vector<rb::ui::Token> tokens = rb::ui::Tokenizer::tokenize(ui_file);

        // Go through the tokens and create an AST UI nodes
        auto node_root = rb::ui::Parser::parse(tokens);

        // Create real UI elements from AST nodes
        root_ = rb::ui::UIFactory::instance().build(*node_root);

    }

    void App::run() {
        if (event_collector_ == nullptr) {
            std::string err = "The program does not have a collection of events from the environment.";
            LOG(err);
            throw std::runtime_error(err);
        }

        infra::intr::Delta_Timer::instance();
        while (running_) {
            // The clock, if the model will run on them
            float delta = infra::intr::Delta_Timer::instance().tick();

            // -- Rendering UI content --

            // Find out the window dimensions
            const infra::math::Vector2 screen_size = renderer_->screen_size();
            // Find out if the window needs to be redrawn (not yet optimized)
            bool redraw = true;

            // Resize the UI to fit the current window
            root_->measure(screen_size);
            root_->layout({0, 0, screen_size.x, screen_size.y});

            // Create an empty frame that will be drawn
            rb::rnd::RenderFrame frame;
            // Create context for UI elements
            const rb::Context ctx(redraw);

            // Collect elements for rendering from the UI
            root_->append_render_items(frame, ctx);

            // Send the frame to render
            renderer_->render(frame);

            // -- Event dispatch --

            event_collector_->collect();
            while (!event_collector_->event_store_.empty()) {
                std::unique_ptr<infra::event::EventConcept> ev =  event_collector_->event_store_.pop_concept();
                if (static_cast<bool>(ev->mask() & infra::event::EventMask::Window)) {
                    g_eventbus_->emit(*ev);
                }
            }
        }
    }
}
