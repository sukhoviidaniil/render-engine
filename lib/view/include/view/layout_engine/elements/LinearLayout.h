/***************************************************************
 * Project:       render-engine
 * File:          LinearLayout.h
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
#ifndef RENDER_ENGINE_LINEARLAYOUT_H
#define RENDER_ENGINE_LINEARLAYOUT_H

#include "UIElement.h"
#include "infra/math/Vector2.h"
#include "view/internal/Alignment.h"
#include "view/internal/Rect.h"

namespace view::ui {

    /**
     * @brief Base class for linear layout containers.
     *
     * Arranges child elements in a single row or column, optionally
     * supporting alignment, spacing, and flexible growth.
     */
    class LinearLayout : public UIElement {
    public:
        ~LinearLayout() override = default;

        /// @brief Alignment of children along the cross axis.
        intrnl::Align align = intrnl::Align::Start;
        /// @brief Spacing between consecutive children.
        float spacing = 0.f;

    protected:
        /**
         * @brief Determines if the layout is horizontal or vertical.
         *
         * Must be implemented by derived classes.
         *
         * @return true if horizontal, false if vertical.
         */
        [[nodiscard]] virtual bool horizontal() const = 0;

        /**
         * @brief Measures the desired size of the layout.
         *
         * Accumulates the sizes of visible children along the main axis
         * and takes the maximum along the cross axis. Spacing between
         * children is included in the measurement.
         *
         * @param available Available space from the parent.
         * @return Desired size of the layout.
         */
        infra::math::Vector2 measure(const infra::math::Vector2 &available) override;

        /**
         * @brief Lays out children within the assigned rectangle.
         *
         * Calculates positions and sizes for each child, taking into
         * account fixed and flexible elements, alignment, and spacing.
         *
         * @param r Final rectangle assigned by the parent layout.
         */
        void layout(intrnl::Rect r) override;
    };
}
#endif //RENDER_ENGINE_LINEARLAYOUT_H