/***************************************************************
 * Project:         Render_Engine
 * File:            Font.cpp
 *
 * Author:          Sukhovii Daniil
 * Contact:
 * Email:           Sukhovii Daniil
 * Created:         2026-02-08
 *
 * Description:     []
 *
 * Disclaimer:
 *  This file is part of Render_Engine.
 *  Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "asset/internal/Font.h"
namespace sif::asset {
    Font::Font() = default;

    Font::~Font() = default;

    Font::Font(Font &&) noexcept = default;

    Font & Font::operator=(Font &&) noexcept = default;

}
