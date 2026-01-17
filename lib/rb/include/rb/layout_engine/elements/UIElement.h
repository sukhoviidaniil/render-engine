/***************************************************************
 * Project:       render-engine
 * File:          UIElement.h
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
#ifndef RENDER_ENGINE_UIELEMENT_H
#define RENDER_ENGINE_UIELEMENT_H

#include <memory>

#include "infra/math/Vector2.h"
#include "rb/internal/Size.h"

#include "rb/ViewContext.h"
#include "LayoutResult.h"
#include "rb/render/RenderFrame.h"

namespace rb::ui {
    /**
     * @brief Base class for all UI layout elements.
     *
     * Represents a node in the layout tree. Each UIElement participates
     * in the measure and layout passes and may contain child elements.
     * The class provides default size resolution and recursive layout
     * propagation.
     */
    class UIElement {
    public:
        /// @brief Virtual destructor.
        virtual ~UIElement() = default;

        /**
         * @brief Adds a child element to this node.
         *
         * Ownership is shared to allow flexible tree composition.
         */
        void add(std::unique_ptr<UIElement> child);

        // ===== Layout API =====

        /**
         * @brief Measures the desired size of the element.
         *
         * Called during the measure pass with the available space
         * provided by the parent. The default implementation resolves
         * the size from width/height constraints.
         *
         * @param available Available space for this element.
         * @return Desired size of the element.
         */
        virtual infra::math::Vector2 measure(const infra::math::Vector2& available);

        /**
         * @brief Assigns the final layout rectangle to the element.
         *
         * Stores the computed rectangle and propagates the same layout
         * to all child elements by default.
         *
         * @param r Final rectangle assigned by the layout engine.
         */
        virtual void layout(intrnl::Rect r);

        virtual void append_render_items(rnd::RenderFrame& frame, const ViewContext& ctx) const;

        // ===== Configuration =====
        intrnl::Size width  = intrnl::Size::auto_(); ///< Width specification
        intrnl::Size height = intrnl::Size::auto_(); ///< Height specification

        infra::math::Vector2 min_size {0, 0};         ///< Minimum allowed size
        infra::math::Vector2 max_size {1e9f, 1e9f};   ///< Maximum allowed size

        infra::math::Vector2 margin  {0, 0}; ///< External spacing
        infra::math::Vector2 padding {0, 0}; ///< Internal spacing

        float flex = 0.f; ///< Flex grow factor (0 = fixed, >0 = expandable)

        bool visible = true; ///< Visibility flag

        LayoutResult result{}; ///< Result of the layout pass

        /// @brief Child elements in the layout tree.
        std::vector<std::unique_ptr<UIElement>> children;
    protected:

        /**
         * @brief Resolves the final size based on available space.
         *
         * Converts width and height Size specifications into concrete
         * values and clamps them to the configured min/max constraints.
         *
         * @param available Available space from the parent.
         * @return Resolved size.
         */
        [[nodiscard]] infra::math::Vector2 resolve_size(const infra::math::Vector2 &available) const;
    };
}

#endif //RENDER_ENGINE_UIELEMENT_H