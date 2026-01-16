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
#include <vector>

#include "AssetRecord.h"
#include "view/internal/GUID.h"

namespace view::assets {

    class AssetImporter {
    public:

        static AssetImporter& instance();

        void load(const std::string& dirpath);

        void load_registry(const std::string& filepath);

        void add(AssetDesc desc);

        AssetDesc get(intrnl::GUID id) const;
        AssetDesc get(const std::string &id) const;

        std::vector<AssetDesc> get() const;
    private:
        AssetImporter();
        mutable std::shared_mutex mtx_;


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