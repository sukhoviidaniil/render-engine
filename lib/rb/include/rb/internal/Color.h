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

#include <charconv>
#include <cstdint>
namespace rb::intrnl {

    struct Color {
        std::uint8_t r = 255, g = 255, b = 255;
        std::uint8_t a = 255;
        Color() = default;
        Color(const std::uint8_t red, const  std::uint8_t green, const std::uint8_t blue, const std::uint8_t alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {

        }

        explicit Color(std::string_view s) {
            std::uint32_t values[4] = {};
            std::size_t count = 0;

            std::size_t pos = 0;
            while (pos < s.size() && count < 4) {
                std::size_t next = s.find('|', pos);
                if (next == std::string_view::npos)
                    next = s.size();

                std::uint32_t v{};
                auto part = s.substr(pos, next - pos);

                auto [ptr, ec] =
                    std::from_chars(part.data(), part.data() + part.size(), v, 10);

                if (ec != std::errc{} || ptr != part.data() + part.size() || v > 255)
                    throw std::invalid_argument("Invalid color component");

                values[count++] = v;
                pos = next + 1;
            }

            if (count != 3 && count != 4)
                throw std::invalid_argument("Color must be r|g|b or r|g|b|a");

            r = static_cast<std::uint8_t>(values[0]);
            g = static_cast<std::uint8_t>(values[1]);
            b = static_cast<std::uint8_t>(values[2]);
            a = (count == 4)
                  ? static_cast<std::uint8_t>(values[3])
                  : static_cast<std::uint8_t>(0);
        }
    };
}


#endif //RENDER_ENGINE_COLOR_H