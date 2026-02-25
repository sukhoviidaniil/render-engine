/***************************************************************
* Project:          Render_Engine
* File:             Sprite.h
*
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2025-12-24
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_AST_RI_SPRITE_H
#define RENDER_ENGINE_AST_RI_SPRITE_H

#include "RenderNode.h"
#include "sif/asset/AssetHandle.h"

namespace sif::rnd {
    struct Sprite : RenderNode {
        void accept(RenderVisitor &v) const override {
            v.visit(*this);
        }

        asset::AssetHandle<void> asset; // SpriteSingle / Atlas / Grid
        uint32_t sprite_id = 0;
    };
}


#endif //RENDER_ENGINE_AST_RI_SPRITE_H