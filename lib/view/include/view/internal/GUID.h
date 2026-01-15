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

#include <cstdint>

namespace view {
    struct GUID {
        std::uint32_t id = 0;

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
    };

    struct GUIDHash {
        size_t operator()(const GUID& g) const noexcept {
            return std::hash<std::uint32_t>{}(g.id);
        }
    };
}

#endif //RENDER_ENGINE_GUID_H