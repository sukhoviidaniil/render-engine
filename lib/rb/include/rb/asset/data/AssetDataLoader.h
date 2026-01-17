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

#include "rb/asset/AssetDesc.h"
#include "rb/asset/data/AssetDataNode.h"
#include "rb/asset/data/FontNode.h"


namespace rb::asset::data {
    class AssetDataLoader {
    public:

        static AssetDataLoader& instance();

        static std::unique_ptr<AssetDataNode> load_from_file(const std::filesystem::path& path);
        static void save_Meta(const std::filesystem::path& path, data::AssetMetaData& meta);

        static std::unique_ptr<FontNode> load_Font_from_file(const std::filesystem::path& path);
        static void save_Meta_Font(const std::filesystem::path& path, data::AssetMetaData& meta);

    private:
        AssetDataLoader();
    };
}

#endif //RENDER_ENGINE_ASSETDATALOADER_H