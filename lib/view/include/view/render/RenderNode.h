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

#include "infra/ast/view/ViewVisitor.h"
#include "view/internal/Rect.h"

namespace view::rnd {

    struct Text;
    struct Rectangle;
    struct Sprite;

    struct RenderVisitor : infra::ast::Visitor {
        virtual void visit(const Text&) {}
        virtual void visit(const Rectangle&) {}
        virtual void visit(const Sprite&) {}
    };

    struct RenderNode  {
        virtual ~RenderNode() = default;

        virtual void accept(RenderVisitor &v) const = 0;

        /// Element dimensions
        Rect rect{};
    };
}


#endif //RENDER_ENGINE_RENDERNODE_H