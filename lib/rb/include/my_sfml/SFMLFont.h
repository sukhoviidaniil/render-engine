/***************************************************************
 * Project:       Render_Engine
 * File:          SFMLFont.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-15
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
#ifndef RENDER_ENGINE_SFML_SFMLFONT_H
#define RENDER_ENGINE_SFML_SFMLFONT_H

#include "SFML/Graphics.hpp"

namespace rb::sfml {
    struct SFMLFont {
        SFMLFont() = default;
        SFMLFont(SFMLFont&&) noexcept = default;
        SFMLFont& operator=(SFMLFont&&) noexcept = default;

        SFMLFont(const SFMLFont&) = delete;
        SFMLFont& operator=(const SFMLFont&) = delete;

        sf::Font font;
    };
}

#endif //RENDER_ENGINE_SFML_SFMLFONT_H