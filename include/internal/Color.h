/***************************************************************
 * Project:       render-engine
 * File:          Color.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-22
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
#ifndef RENDER_ENGINE_COLOR_H
#define RENDER_ENGINE_COLOR_H


#include <cstdint>
#include <string>
#include <string_view>

namespace sif::intrnl {
    class Color {
    public:

        Color();

        Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);

        explicit Color(std::string_view s, std::string separator = "|");

        std::uint8_t r = 255, g = 255, b = 255;
        std::uint8_t a = 255;
    };
}


#endif //RENDER_ENGINE_COLOR_H