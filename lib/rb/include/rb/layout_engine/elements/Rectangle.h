/***************************************************************
 * Project:       render-engine
 * File:          Rectangle.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-26
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
#ifndef RENDER_ENGINE_RECTANGLE_H
#define RENDER_ENGINE_RECTANGLE_H


#include "UIElement.h"
#include "rb/internal/Color.h"

namespace rb::ui {

    class Rectangle : public UIElement {
    public:
        explicit Rectangle();
        explicit Rectangle(
            intrnl::Color fill,
            intrnl::Color border = {},
            int border_w = 0
        );

        infra::math::Vector2 measure(const infra::math::Vector2& available) override;

        void append_render_items(rnd::RenderFrame& frame, const ViewContext& ctx) const override;

        intrnl::Color fill_color;
        intrnl::Color border_color;
        int border_width = 0;

    private:
        static float resolve(const intrnl::Size& s, float avail);
    };

}


#endif //RENDER_ENGINE_RECTANGLE_H