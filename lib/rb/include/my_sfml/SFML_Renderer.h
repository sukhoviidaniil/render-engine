/***************************************************************
 * Project:       render-engine
 * File:          SFML_Renderer.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-06
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
#ifndef RENDER_ENGINE_SFML_SFML_RENDERER_H
#define RENDER_ENGINE_SFML_SFML_RENDERER_H

#include "rb/Renderer.h"
#include "rb/ast/RB_Config.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "my_sfml/ISFML_Event_Source.h"

namespace rb::sfml {
    class SFML_Renderer final: public Renderer, public ISFML_Event_Source {
    public:
        ~SFML_Renderer() override;
        explicit SFML_Renderer(const ast::RB_Config &info);

        void track_local(const std::shared_ptr<infra::event::Event_Bus>& bus) override;
        void track_global(const std::shared_ptr<infra::event::Event_Bus>& bus) override;

        [[nodiscard]] infra::math::Vector2 screen_size() const override;

        void render(const rnd::RenderFrame& graph) override;

        bool poll_event(sf::Event& e) override;

    private:
        void visit(const rnd::Text& r) override;
        void visit(const rnd::Rectangle& r) override;
        void visit(const rnd::Sprite& r) override;

        sf::RenderWindow window_;
    };
}

#endif //RENDER_ENGINE_SFML_SFML_RENDERER_H