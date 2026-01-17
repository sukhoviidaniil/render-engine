/***************************************************************
 * Project:       render-engine
 * File:          RI_Rectangle.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-24
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
#ifndef RENDER_ENGINE_AST_RI_RECTANGLE_H
#define RENDER_ENGINE_AST_RI_RECTANGLE_H


#include "rb/render/RenderNode.h"
#include "rb/internal/Color.h"

namespace rb::rnd {
    struct Rectangle : RenderNode {
        void accept(RenderVisitor &v) const override {
            v.visit(*this);
        }

        int border_width = 0;
        intrnl::Color border_color{};
        intrnl::Color color{};
    };
}

#endif //RENDER_ENGINE_AST_RI_RECTANGLE_H
