/***************************************************************
 * Project:       render-engine
 * File:          Size.h
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
#ifndef RENDER_ENGINE_SIZE_H
#define RENDER_ENGINE_SIZE_H

namespace view  {
    /**
     * @brief Size specification used by the layout engine.
     *
     * Represents how a dimension (width or height) should be resolved:
     * automatically, in absolute pixels, relative percentages, or
     * logical layout units.
     */
    struct Size {
        /**
         * @brief Size interpretation mode.
         */
        enum class Type {
            Auto,       ///< Size is determined automatically by layout rules
            Pixel,       ///< Absolute size in pixels
            Percent,    ///< Size relative to the parent (0–100)
        };

        Type  type  = Type::Auto;   ///< Size mode
        float value = 0.f;          ///< Associated value (meaning depends on type)

        /// @brief Automatic size.
        static Size auto_() { return {}; }

        /// @brief Absolute size in pixels.
        static Size px(float v) { return {Type::Pixel, v}; }

        /// @brief Relative size in percent of parent.
        static Size percent(float v) { return {Type::Percent, v}; }
    };
}

#endif //RENDER_ENGINE_SIZE_H