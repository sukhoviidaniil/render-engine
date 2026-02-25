/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2025-12-27
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_UI_SPRITEELEMENT_H
#define RENDER_ENGINE_UI_SPRITEELEMENT_H


#include "UIElement.h"


namespace sif::ui {
    class Sprite : public UIElement {
    public:
        explicit Sprite(std::string  sprite, float sprite_width, float sprite_height);

        infra::math::Vector2 measure(const infra::math::Vector2& available) override;

        void append_render_items(rnd::RenderFrame& frame, const rnd::FrameContext& /*ctx*/) const override;

    private:
        static float resolve(const intrnl::Size& s, float avail);

        std::string sprite_;
    };
}

#endif //RENDER_ENGINE_UI_SPRITEELEMENT_H