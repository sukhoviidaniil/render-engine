/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-12
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "sif/layout_engine/elements/Text.h"
#include "sif/render/elements/Text.h"

namespace sif::ui {

    infra::math::Vector2 Text::measure(const infra::math::Vector2 &available)  {
        if (!font.ready() || text.empty()) {
            return {0.f, 0.f};
        }

        // Simple logic: width = number of characters * width of one character
        float charWidth = stretch_font ? fontSize * 1.1f : fontSize * 1.0f; // can be adjusted to fit the font
        float width = charWidth * static_cast<float>(text.size());

        // Height = font size
        float height = static_cast<float>(fontSize);

        // Limit to available space
        width  = std::min(width, available.x);
        height = std::min(height, available.y);

        return {width, height};
    }

    void Text::append_render_items(rnd::RenderFrame &frame, const rnd::FrameContext &ctx) const {
        if (!font.ready() || text.empty()) return;
        std::unique_ptr<rnd::Text> item = std::make_unique<rnd::Text>();

        item->rect = result.rect;
        item->font = font;
        item->text  = text;
        item->size = fontSize;
        item->color = color;
        frame.constant_items.push_back(std::move(item));
    }
}
