/***************************************************************
 * Project:       Render_Engine
 * File:          GUID.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-13
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
#ifndef RENDER_ENGINE_GUID_H
#define RENDER_ENGINE_GUID_H

#include <charconv>
#include <cstdint>

namespace rb::intrnl{
    struct GUID {
        std::uint32_t id = 0;

        GUID() = default;
        explicit GUID(const std::uint32_t i) : id(i){}
        explicit GUID(const std::string& i){
            std::uint32_t value{};
            const char* begin = i.data();
            const char* end   = i.data() + i.size();

            auto [ptr, ec] = std::from_chars(begin, end, value, 10);

            // the string must be parsed completely and without errors
            if (ec != std::errc{} || ptr != end) {
                throw std::invalid_argument("Invalid GUID string: " + i);
            }

            id = value;
        }

        // equality
        friend constexpr bool operator==(const GUID& a, const GUID& b) noexcept {
            return a.id == b.id;
        }

        // ordering
        friend constexpr bool operator<(const GUID& a, const GUID& b) noexcept {
            return a.id < b.id;
        }

        friend constexpr bool operator>(const GUID& a, const GUID& b) noexcept {
            return a.id > b.id;
        }

        [[nodiscard]] std::string string() const {
            return std::to_string(id);
        }
    };

    struct GUIDHash {
        size_t operator()(const GUID& g) const noexcept {
            return std::hash<std::uint32_t>{}(g.id);
        }
    };
}

#endif //RENDER_ENGINE_GUID_H