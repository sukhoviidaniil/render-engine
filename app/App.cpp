/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-02-25
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#include "App.h"


#include "Graphics_Factory.h"
#include "sif/diagnostics/Logger.h"
#include "sif/event/events/window.hpp"
#include "../sif/include/sif/internal/Delta_Timer.h"
#include "sif/layout_engine/Parser.h"
#include "sif/layout_engine/Tokenizer.h"
#include "sif/layout_engine/UIFactory.h"


App::~App() = default;

App::App(
    const std::shared_ptr<event::Event_Bus> &eventbus,
    const App::Config &rb_config,
    const event::Event_Collector & ecoll_config,
    const std::string& ui_file)
:g_eventbus_(eventbus) {

    // Be sure to track at least one event that will complete the cycle.
    track(
        eventbus->subscribe<event::window::Window_Closed>(
            [this](const event::window::Window_Closed&) {
                running_ = false;
            }
        )
    );

    // Creating a renderer and event collector
    renderer_ = Graphics_Factory::instance().make_Renderer(rb_config);
    event_collector_ = Graphics_Factory::instance().make_Event_Collector(ecoll_config);

    // -- The next part is related to the UI. --

    // Read and tokenize UI data
    std::vector<ui::Token> tokens = ui::Tokenizer::tokenize(ui_file);

    // Go through the tokens and create an AST UI nodes
    auto node_root = ui::Parser::parse(tokens);

    // Create real UI elements from AST nodes
    root_ = ui::UIFactory::instance().build(*node_root);
}

void App::run() {
    if (event_collector_ == nullptr) {
        std::string err = "The program does not have a collection of events from the environment.";
        LOG(err);
        throw std::runtime_error(err);
    }

    intrnl::Delta_Timer::instance();
    while (running_) {
        // The clock, if the model will run on them
        float delta = intrnl::Delta_Timer::instance().tick();

        // -- Rendering UI content --

        // Find out the window dimensions
        const math::Vector2 screen_size = renderer_->screen_size();
        // Find out if the window needs to be redrawn (not yet optimized)
        bool redraw = true;

        // Resize the UI to fit the current window
        root_->measure(screen_size);
        root_->layout({0, 0, screen_size.x, screen_size.y});

        // Create an empty frame that will be drawn
        rnd::RenderFrame frame;
        // Create context for UI elements
        const rnd::FrameContext ctx(redraw);

        // Collect elements for rendering from the UI
        root_->append_render_items(frame, ctx);

        // Send the frame to render
        renderer_->render(frame);

        // -- Event dispatch --

        event_collector_->collect();
        while (!event_collector_->event_store_.empty()) {
            std::unique_ptr<event::EventConcept> ev =  event_collector_->event_store_.pop_concept();
            if (static_cast<bool>(ev->mask() & event::EventMask::Window)) {
                g_eventbus_->emit(*ev);
            }
        }
    }
}
