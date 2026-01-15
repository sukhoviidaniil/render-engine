/***************************************************************
 * Project:       Pacman
 * File:          UIElement.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-11
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Pacman.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "view/layout_engine/elements/UIElement.h"

namespace view::ui {
    void UIElement::add(std::unique_ptr<UIElement> child)  {
        children.push_back(std::move(child));
    }

    infra::math::Vector2 UIElement::measure(const infra::math::Vector2 &available)  {
        infra::math::Vector2 total_size {0, 0};

        for (auto& child : children) {
            auto child_size = child->measure(available);
            total_size.y += child_size.y + child->margin.y;
            total_size.x = std::max(total_size.x, child_size.x + child->margin.x);
        }

        total_size.x += padding.x * 2;
        total_size.y += padding.y * 2;

        total_size.x = std::clamp(total_size.x, min_size.x, max_size.x);
        total_size.y = std::clamp(total_size.y, min_size.y, max_size.y);

        return total_size;
    }

    void UIElement::layout(const intrnl::Rect r)  {
        result.rect = r;

        float y_offset = r.y + padding.y;

        for (auto& child : children) {
            infra::math::Vector2 child_size = child->resolve_size({r.width - padding.x*2, r.height - padding.y*2});

            intrnl::Rect child_rect {
                r.x + padding.x + child->margin.x,
                y_offset + child->margin.y,
                child_size.x,
                child_size.y
            };

            child->layout(child_rect);

            y_offset += child_size.y + child->margin.y;
        }
    }

    void UIElement::append_render_items(rnd::RenderFrame &frame, const ViewContext &ctx) const  {
        for (const auto& c : children) {
            c->append_render_items(frame, ctx);
        }
    }

    infra::math::Vector2 UIElement::resolve_size(const infra::math::Vector2 &available) const  {
        infra::math::Vector2 out;

        auto resolve = [&](const intrnl::Size s, const float avail) {
            if (s.type == intrnl::Size::Type::Pixel)   return s.value;
            if (s.type == intrnl::Size::Type::Percent) return avail * s.value;
            return avail; // Auto
        };

        out.x = resolve(width,  available.x);
        out.y = resolve(height, available.y);

        out.x = std::clamp(out.x, min_size.x, max_size.x);
        out.y = std::clamp(out.y, min_size.y, max_size.y);

        return out;
    }
}
