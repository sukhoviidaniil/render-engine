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

#include "infra/ast/view/ViewNode.h"
#include "infra/ast/view/ViewVisitor.h"

namespace view::ui {

    struct RI_Label;
    struct RI_Rectangle;
    struct RI_Sprite;
    struct RI_ComplexSprite;

    struct RenderVisitor : infra::ast::Visitor {
        virtual void visit(const RI_Label&) {}
        virtual void visit(const RI_Rectangle&) {}
        virtual void visit(const RI_Sprite&) {}
        virtual void visit(const RI_ComplexSprite&) {}
    };

    struct RenderNode : infra::ast::Node {
        /// Element dimensions
        infra::ui::Rect rect{};
        virtual void accept(RenderVisitor &v) const = 0;
    };
}


#endif //RENDER_ENGINE_RENDERNODE_H