/***************************************************************
 * Project:       Render_Engine
 * File:          SFML_Renderer.cpp
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

#include "my_sfml/SFML_Renderer.h"

#include "infra/event/events/window.hpp"
#include "sif/render/Rectangle.h"
#include "sif/render/Text.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"


namespace sif::sfml {
    SFML_Renderer::~SFML_Renderer() = default;

    SFML_Renderer::SFML_Renderer(const ast::RB_Config &info) : window_(sf::VideoMode(info.window_width, info.window_height), info.window_name) {
        sf::View view(sf::FloatRect(0, 0, static_cast<float>(info.window_width), static_cast<float>(info.window_height)));
        window_.setView(view);
        window_.setFramerateLimit(static_cast<unsigned int>(info.fps));
    }

    void SFML_Renderer::track_local(const std::shared_ptr<infra::event::Event_Bus> &bus) {
    }

    void SFML_Renderer::track_global(const std::shared_ptr<infra::event::Event_Bus> &bus) {\

        using namespace infra::event::window;
        // Closing the window
        track(
            bus->subscribe<Window_Closed>(
                [this](const Window_Closed&) {
                    window_.close();
                }
            )
        );
        // Change window size
        track(
            bus->subscribe<Window_Resized>(
                [this](const Window_Resized& e) {
                    sf::View v = window_.getView();
                    v.setSize(static_cast<float>(e.width),
                              static_cast<float>(e.height));
                    v.setCenter(v.getSize() * 0.5f);
                    window_.setView(v);
                }
            )
        );
    }

    infra::math::Vector2 SFML_Renderer::screen_size() const {
        return {static_cast<float>(window_.getSize().x), static_cast<float>(window_.getSize().y)};
    }

    void SFML_Renderer::render(const rnd::RenderFrame &graph) {
        window_.clear();
        for (auto& item : graph.constant_items) {
            item->accept(*this);
        }
        for (auto& item : graph.temp_items) {
            item->accept(*this);
        }
        window_.display();
    }

    bool SFML_Renderer::poll_event(sf::Event &e) {
        return window_.pollEvent(e);
    }

    void SFML_Renderer::visit(const rnd::Text & r) {
        rgst::AssetHandle<asset::Font> ast_h = r.font;
        if (!ast_h.ready()) {
            return;
        }
        asset::Font* f = ast_h.get();

        sf::Text text;
        text.setFont(f->sfml().font);
        text.setString(r.text);
        text.setFillColor(sf::Color(
            r.color.r,
            r.color.g,
            r.color.b,
            r.color.a
        ));
        const auto& rect = r.rect;

        if (r.size > 0) {
            // Fixed size
            text.setCharacterSize(static_cast<unsigned>(r.size));
            text.setPosition(rect.x, rect.y);
        } else {
            // Stretch the text across the entire Rect
            text.setCharacterSize(30); // base size for calculation

            sf::FloatRect bounds = text.getLocalBounds();

            // origin for correct scaling
            text.setOrigin(bounds.left, bounds.top);

            float scaleX = rect.width / bounds.width;
            float scaleY = rect.height / bounds.height;

            text.setScale(scaleX, scaleY);
            text.setPosition(rect.x, rect.y);
        }

        window_.draw(text);
    }

    void SFML_Renderer::visit(const rnd::Rectangle & r) {
        sf::RectangleShape rect;

        rect.setPosition(r.rect.x, r.rect.y);
        rect.setSize({ r.rect.width, r.rect.height });

        rect.setFillColor(
            sf::Color(r.color.r, r.color.g, r.color.b, r.color.a)
        );

        if (r.border_width > 0) {
            rect.setOutlineThickness(static_cast<float>(r.border_width));
            rect.setOutlineColor(
                sf::Color(
                    r.border_color.r,
                    r.border_color.g,
                    r.border_color.b,
                    r.border_color.a
                )
            );
        } else {
            rect.setOutlineThickness(0.f);
        }
        window_.draw(rect);
    }

    void SFML_Renderer::visit(const rnd::Sprite & r) {
    }
}

