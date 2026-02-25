/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-19
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_RECT_H
#define RENDER_ENGINE_RECT_H

namespace sif::intrnl{
    /**
     * @brief Axis-aligned rectangle in layout coordinates.
     *
     * Used internally by the layout engine to represent the final
     * position and size of UI elements.
     */
    struct Rect {
        float x = 0; ///< X position (left)
        float y = 0; ///< Y position (top)
        float width = 0; ///< Width
        float height = 0; ///< Height

        Rect() = default;
        Rect(const float x, const float y, const float width, const float height) : x(x), y(y), width(width), height(height) {}
    };
}
#endif //RENDER_ENGINE_RECT_H