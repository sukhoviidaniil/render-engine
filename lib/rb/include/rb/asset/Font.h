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
#include "sfml/SFMLFont.h"

namespace rb::asset {
    class Font {
    public:
        Font() = default;
        Font(Font&&) noexcept = default;
        Font& operator=(Font&&) noexcept = default;

        Font(const Font&) = delete;
        Font& operator=(const Font&) = delete;

        [[nodiscard]] bool valid() const {
            return data_.valid();
        }

        explicit Font(sfml::SFMLFont backend)
            :data_(std::move(backend)) {
        }

        [[nodiscard]] const sfml::SFMLFont& sfml() const {
            return data_.get<sfml::SFMLFont>();
        }

        sfml::SFMLFont& sfml() {
            return data_.get<sfml::SFMLFont>();
        }

    private:
        infra::intr::ErasedObject data_;
    };
}

#endif //RENDER_ENGINE_ASSETS_FONT_H