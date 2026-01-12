/***************************************************************
 * Project:       render-engine
 * File:          RI_Sprite.h
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
#ifndef RENDER_ENGINE_AST_RI_SPRITE_H
#define RENDER_ENGINE_AST_RI_SPRITE_H



#include "view/render/RenderNode.h"

namespace view::rnd {
    struct Sprite : RenderNode {
        void accept(RenderVisitor &v) const override {
            v.visit(*this);
        }
    };
}


#endif //RENDER_ENGINE_AST_RI_SPRITE_H