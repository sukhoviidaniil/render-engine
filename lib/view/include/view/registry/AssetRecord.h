/***************************************************************
 * Project:       Render_Engine
 * File:          AssetRecord.h
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
#ifndef RENDER_ENGINE_ASSETRECORD_H
#define RENDER_ENGINE_ASSETRECORD_H
#include <memory>
#include <string>


#include "view/internal/AssetState.h"
#include "view/internal/AssetType.h"
#include "view/internal/GUID.h"

namespace view::assets {
    struct AssetRecord {
        GUID guid;
        std::string asset_name;
        std::string path;
        AssetType type;

        AssetState state = AssetState::NotRequested;
        std::shared_ptr<void> data;
    };
}

#endif //RENDER_ENGINE_ASSETRECORD_H