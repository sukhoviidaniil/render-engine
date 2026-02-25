/***************************************************************
 * Project:       Render_Engine
 * File:          IAssetLoader.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-02-01
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

#include "asset/internal/IAssetLoader.h"

#include "infra/diagnostics/Logger.h"

namespace sif::asset {
    IAssetLoader::~IAssetLoader() = default;

    void IAssetLoader::try_load(AssetRecord &record, const std::string &asset_dir) {
        const std::string& asset_name = record.get_meta().asset_name;
        LOG("Start loading asset: " + asset_name);
        try {
            load_asset(record, asset_dir);
            record.set_state(AssetState::Ready);
            LOG("Successfully loaded asset: " + asset_name);
        } catch (...) {
            record.set_state(AssetState::Failed);
            std::string err = "Failed to load asset: " + asset_name;
            std::throw_with_nested(
                std::runtime_error(err)
            );
        }
    }
}
