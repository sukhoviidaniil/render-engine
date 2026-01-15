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

#include "view/render/RenderNode.h"
#include "view/internal/Color.h"
#include "view/registry/AssetHandle.h"
#include "view/registry/assets/Font.h"

namespace view::rnd {
    struct Text : RenderNode {
        void accept(RenderVisitor &v) const override {
            v.visit(*this);
        }

        /**
         * @brief Any text
         */
        std::string text;
        intrnl::Color color;
        int size = 0;

        assets::AssetHandle<assets::Font> font;
    };
}

#endif //RENDER_ENGINE_AST_RI_TEXT_H