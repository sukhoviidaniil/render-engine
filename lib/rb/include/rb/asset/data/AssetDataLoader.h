/***************************************************************
 * Project:       Render_Engine
 * File:          AssetDataLoader.h
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
#ifndef RENDER_ENGINE_ASSETDATALOADER_H
#define RENDER_ENGINE_ASSETDATALOADER_H
#include <filesystem>
#include <optional>
#include <vector>

#include "rb/asset/AssetRecord.h"

namespace rb::asset::data {
    class AssetDataLoader {
    public:
        virtual ~AssetDataLoader() = default;

        static AssetDataLoader& instance();

        virtual std::optional<AssetDesc> load_from_file(const std::filesystem::path& path);
        virtual std::vector<AssetDesc> load_from_config(const std::filesystem::path& path);

    private:
        AssetDataLoader();
    };
}

#endif //RENDER_ENGINE_ASSETDATALOADER_H