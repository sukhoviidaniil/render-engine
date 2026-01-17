/***************************************************************
 * Project:       render-engine
 * File:          RenderNode.h
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
#ifndef RENDER_ENGINE_RENDERNODE_H
#define RENDER_ENGINE_RENDERNODE_H

#include "rb/internal/Rect.h"

namespace rb::rnd {

    struct Text;
    struct Rectangle;
    struct Sprite;

    struct RenderVisitor {
        virtual ~RenderVisitor() = default;

        virtual void visit(const Text&) = 0;
        virtual void visit(const Rectangle&) = 0;
        virtual void visit(const Sprite&) = 0;
    };

    struct RenderNode  {
        virtual ~RenderNode() = default;

        virtual void accept(RenderVisitor &v) const = 0;

        /// Element dimensions
        intrnl::Rect rect{};
    };
}


#endif //RENDER_ENGINE_RENDERNODE_H