/***************************************************************
 * Project:       render-engine
 * File:          SpriteElement.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-27
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
#ifndef RENDER_ENGINE_UI_SPRITEELEMENT_H
#define RENDER_ENGINE_UI_SPRITEELEMENT_H


#include "UIElement.h"


namespace view::ui {
    class SpriteElement : public UIElement {
    public:
        explicit SpriteElement(std::string  sprite, float sprite_width, float sprite_height);

        infra::math::Vector2 measure(const infra::math::Vector2& available) override;

        void append_render_items(rnd::RenderFrame& frame, const ViewContext& /*ctx*/) const override;

    private:
        static float resolve(const intrnl::Size& s, float avail);

        std::string sprite_;
    };
}

#endif //RENDER_ENGINE_UI_SPRITEELEMENT_H