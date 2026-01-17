/***************************************************************
 * Project:       render-engine
 * File:          Base.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-19
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
#ifndef RENDER_ENGINE_RECT_H
#define RENDER_ENGINE_RECT_H

namespace rb::intrnl{
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