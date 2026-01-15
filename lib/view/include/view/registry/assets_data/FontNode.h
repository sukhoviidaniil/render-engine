/***************************************************************
 * Project:       Render_Engine
 * File:          FontNode.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-14
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Render_Engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_FONTNODE_H
#define RENDER_ENGINE_FONTNODE_H
#include "AssetDataNode.h"

namespace view::assets {
    struct FontNode : AssetDataNode {
        ~FontNode() override = default;
        void accept(AssetDataVisitor &v) const override {
        }
        intrnl::AssetType type() const override {
            return intrnl::AssetType::Font;
        }
    };
}

#endif //RENDER_ENGINE_FONTNODE_H