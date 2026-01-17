/***************************************************************
 * Project:       Render_Engine
 * File:          AssetImporter.h
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
#ifndef RENDER_ENGINE_ASSETIMPORTER_H
#define RENDER_ENGINE_ASSETIMPORTER_H
#include <shared_mutex>


#include "rb/asset/AssetRecord.h"
#include "rb/internal/GUID.h"

namespace rb::rgst {
    class AssetImporter {
    public:

        static AssetImporter& instance();

        void load_from_path(const std::string& dirpath);
        void save_in_file(const std::string& filepath);
        void load_from_file(const std::string& filepath);

        void load_in_registry();

        asset::AssetDesc get(const std::string &id) const;

    private:
        AssetImporter();
        void add(asset::AssetDesc& desc);
        mutable std::shared_mutex mtx_;

        std::unordered_set<intrnl::GUID, intrnl::GUIDHash> guids_;

        std::unordered_map<
            intrnl::GUID,
            asset::AssetDesc,
            intrnl::GUIDHash
        >
        by_guid_;

        std::unordered_map<
            std::string,
            asset::AssetDesc
        >
        by_asset_name_;
    };
}

#endif //RENDER_ENGINE_ASSETIMPORTER_H