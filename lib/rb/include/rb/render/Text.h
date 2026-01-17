/***************************************************************
 * Project:       render-engine
 * File:          RI_Text.h
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
#ifndef RENDER_ENGINE_AST_RI_TEXT_H
#define RENDER_ENGINE_AST_RI_TEXT_H

#include <string>

#include "rb/render/RenderNode.h"
#include "rb/internal/Color.h"
#include "rb/registry/AssetHandle.h"
#include "rb/asset/Font.h"

namespace rb::rnd {
    struct Text : RenderNode {
        void accept(RenderVisitor &v) const override {
            v.visit(*this);
        }

        rgst::AssetHandle<asset::Font> font;
        intrnl::Color color;
        int size = 0;
        /**
         * @brief Any text
         */
        std::string text;
    };
}

#endif //RENDER_ENGINE_AST_RI_TEXT_H