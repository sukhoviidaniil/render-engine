/***************************************************************
 * Project:       render-engine
 * File:          RenderFrame.h
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
#ifndef RENDER_ENGINE_AST_RENDERFRAME_H
#define RENDER_ENGINE_AST_RENDERFRAME_H

#include <memory>
#include <vector>

#include "rb/render/RenderNode.h"

namespace rb::rnd {
    struct RenderFrame {
        std::vector<std::unique_ptr<RenderNode>> constant_items;
        std::vector<std::unique_ptr<RenderNode>> temp_items;
    };
}

#endif //RENDER_ENGINE_AST_RENDERFRAME_H