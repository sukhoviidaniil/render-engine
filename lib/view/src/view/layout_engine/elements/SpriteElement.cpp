/***************************************************************
 * Project:       Pacman
 * File:          SpriteElement.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-12
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

#include "view/layout_engine/elements/SpriteElement.h"
#include "view/render/Sprite.h"

namespace view::ui {
    SpriteElement::SpriteElement(std::string sprite, const float sprite_width, const float sprite_height)
        : sprite_(std::move(sprite)) {

        width.value = sprite_width;
        height.value = sprite_height;
    }

    infra::math::Vector2 SpriteElement::measure(const infra::math::Vector2 &available)  {
        infra::math::Vector2 size{
            std::max(0.f, available.x),
            std::max(0.f, available.y)
        };

        size.x = resolve(width, available.x);
        size.y = resolve(height, available.y);

        size.x = std::clamp(size.x, min_size.x, max_size.x);
        size.y = std::clamp(size.y, min_size.y, max_size.y);

        return size;
    }

    void SpriteElement::append_render_items(rnd::RenderFrame &frame, const ViewContext &view_context) const  {
        if (!visible) return;

        auto item = std::make_unique<rnd::Sprite>();
        // item->sprite = sprite_;
        item->rect = result.rect;
        frame.constant_items.push_back(std::move(item));
    }

    float SpriteElement::resolve(const intrnl::Size &s, float avail)  {
        switch (s.type) {
            case intrnl::Size::Type::Pixel:   return s.value;
            case intrnl::Size::Type::Percent: return avail * s.value;
            default:                  return avail;
        }
    }
}
