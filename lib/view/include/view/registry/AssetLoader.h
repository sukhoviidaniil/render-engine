/***************************************************************
 * Project:       Render_Engine
 * File:          AssetLoader.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-16
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
#ifndef RENDER_ENGINE_ASSETLOADER_H
#define RENDER_ENGINE_ASSETLOADER_H
#include <filesystem>
#include <optional>
#include <vector>

#include "AssetRecord.h"

namespace view::assets {
    class AssetLoader {
    public:
        static AssetLoader& instance();

        virtual std::optional<AssetDesc> load_from_file(const std::filesystem::path& path);
        virtual std::vector<AssetDesc> load_from_config(const std::filesystem::path& path);

    private:
        AssetLoader();
    };
}

#endif //RENDER_ENGINE_ASSETLOADER_H