/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-17
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETDATALOADER_H
#define RENDER_ENGINE_ASSETDATALOADER_H

#include <filesystem>

#include "AssetDataNode.h"
#include "FontNode.h"


namespace sif::asset::data {
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