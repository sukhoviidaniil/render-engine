/***************************************************************
 * Project:       Render_Engine
 * File:          AssetDataShort.h
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
#ifndef RENDER_ENGINE_ASSETDATASHORT_H
#define RENDER_ENGINE_ASSETDATASHORT_H
#include <string>
#include <unordered_map>

#include "view/internal/AssetType.h"
#include "view/internal/GUID.h"
namespace view::assets {
    struct AssetMetaData {
        intrnl::GUID guid;
        intrnl::AssetType type = intrnl::AssetType::Undefined;
        std::string asset_name = "NONE";

        std::unordered_map<
            uint32_t,
            std::string
        > record_id_to_name;

        std::unordered_map<
            std::string,
            uint32_t
        > record_name_to_id;
    };
}

#endif //RENDER_ENGINE_ASSETDATASHORT_H