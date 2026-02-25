/***************************************************************
 * Project:       Render_Engine
 * File:          Font.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-14
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Render_Engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETS_FONT_H
#define RENDER_ENGINE_ASSETS_FONT_H

#include "infra/internal/ErasedObject.h"
#include "infra/math/Vector2.h"

namespace sif::asset {
    class Font {
    public:

        Font(const Font&) = delete;
        Font& operator=(const Font&) = delete;

        Font();
        virtual ~Font();
        Font(Font&&) noexcept;
        Font& operator=(Font&&) noexcept;

        [[nodiscard]] virtual infra::math::Vector2 measure_text(const std::string& str, unsigned int size) const = 0;
    };
}

#endif //RENDER_ENGINE_ASSETS_FONT_H