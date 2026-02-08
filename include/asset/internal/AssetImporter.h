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
#include <unordered_map>


#include "asset/internal/AssetDesc.h"
#include "asset/internal/AssetRecord.h"
#include "internal/GUID.h"

namespace sif::asset {
    class AssetImporter {
    public:

        static AssetImporter& instance();

        void load_from_path(const std::string& dirpath);
        void save_in_file(const std::string& filepath);
        void load_from_file(const std::string& filepath);

        void load_in_registry();

        AssetDesc get(const std::string &id) const;

    private:
        AssetImporter();
        void add(AssetDesc& desc);
        mutable std::shared_mutex mtx_;

        std::unordered_set<intrnl::GUID, intrnl::GUIDHash> guids_;

        std::unordered_map<
            intrnl::GUID,
            AssetDesc,
            intrnl::GUIDHash
        >
        by_guid_;

        std::unordered_map<
            std::string,
            AssetDesc
        >
        by_asset_name_;
    };
}

#endif //RENDER_ENGINE_ASSETIMPORTER_H