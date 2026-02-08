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
#include <stdexcept>
#include <string>
#include <unordered_set>

#include "infra/internal/Random.h"

namespace sif::intrnl {
    struct GUID {
        std::uint32_t id = 0;

        GUID();
        explicit GUID(std::uint32_t i);
        explicit GUID(const std::string& i);

        [[nodiscard]] std::string string() const;

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

    inline GUID generate_guid(const std::unordered_set<GUID, GUIDHash>& existing) {
        GUID g;
        do {
            g = GUID{
                static_cast<std::uint32_t>(
                    infra::intr::Random::instance().next_int(
                        1,
                        static_cast<int>(std::numeric_limits<std::uint32_t>::max())
                    )
                )
            };
        } while (existing.contains(g));

        return g;
    }
}

#endif //RENDER_ENGINE_GUID_H