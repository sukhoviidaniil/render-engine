/***************************************************************
 * Project:       Render_Engine
 * File:          AssetDesc.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-17
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
#ifndef RENDER_ENGINE_ASSETDESC_H
#define RENDER_ENGINE_ASSETDESC_H

#include <string>
#include <utility>

#include "rb/asset/data/AssetMetaData.h"

namespace rb::asset {
    struct AssetDesc {
        AssetDesc() = default;
        AssetDesc(std::string c, data::AssetMetaData m) : conf_path(std::move(c)), meta(std::move(m)) {

        }

        std::string conf_path;
        data::AssetMetaData meta;
    };
}

#endif //RENDER_ENGINE_ASSETDESC_H