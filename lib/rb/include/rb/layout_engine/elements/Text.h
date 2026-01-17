/***************************************************************
 * Project:       render-engine
 * File:          Text.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-26
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
#ifndef RENDER_ENGINE_TEXT_H
#define RENDER_ENGINE_TEXT_H
#include "UIElement.h"
#include "rb/internal/Color.h"
#include "rb/registry/AssetHandle.h"
#include "rb/registry/assets/Font.h"


namespace rb::ui {
    /**
     * @brief Simple text label UI element.
     *
     */
    class Text : public UIElement {
    public:
        /// @brief Virtual destructor.
        ~Text() override = default;
        explicit Text(assets::AssetHandle<assets::Font> f)
        : font(std::move(f)){

        }


        /**
         * @brief Measures the desired size of the text.
         *
         * Uses a simplified text metric: a fixed width per character
         * and a constant line height.
         *
         * @param available Available space.
         * @return Desired size of the text.
         */
        infra::math::Vector2 measure(const infra::math::Vector2& available) override;

        std::string text;

        intrnl::Color color = intrnl::Color(255,255,255);

        assets::AssetHandle<assets::Font> font;

        int fontSize = 14;

        bool stretch_font = false;
    };

}

#endif //RENDER_ENGINE_TEXT_H