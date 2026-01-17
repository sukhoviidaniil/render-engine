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
#include "SFML/Graphics/RenderWindow.hpp"


namespace rb::sfml {
    class SFML_Renderer final: public Renderer {
    public:
        ~SFML_Renderer() override;
        explicit SFML_Renderer();

        void track_local(const std::shared_ptr<infra::event::Event_Bus>& bus) override;
        void track_global(const std::shared_ptr<infra::event::Event_Bus>& bus) override;

        [[nodiscard]] infra::math::Vector2 screen_size() const override;

        void render(const rnd::RenderFrame& graph) override;

    private:
        void visit(const rnd::Text&) override;
        void visit(const rnd::Rectangle&) override;
        void visit(const rnd::Sprite&) override;

        sf::RenderWindow window_;
    };
}

#endif //RENDER_ENGINE_SFML_SFML_RENDERER_H