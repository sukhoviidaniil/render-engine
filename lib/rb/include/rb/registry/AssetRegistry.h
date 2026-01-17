/***************************************************************
 * Project:       Render_Engine
 * File:          AssetRegistry.h
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
#ifndef RENDER_ENGINE_ASSETREGISTRY_H
#define RENDER_ENGINE_ASSETREGISTRY_H

#include <unordered_map>

#include "rb/asset/IAssetLoader.h"
#include "rb/registry/AssetHandle.h"
#include "rb/asset/AssetRecord.h"

namespace rb::rgst {
    class AssetRegistry{
    public:
        static AssetRegistry& instance();

        AssetRegistry(const AssetRegistry&) = delete;
        AssetRegistry& operator=(const AssetRegistry&) = delete;
        AssetRegistry(AssetRegistry&&) = delete;
        AssetRegistry& operator=(AssetRegistry&&) = delete;

        void set_asset_dir(const std::string& dir);

        void register_loader(
            asset::AssetType type,
            std::unique_ptr<asset::IAssetLoader> loader
            );

        void add_AssetRecord(asset::AssetDesc desc);
        void add_AssetRecord(const asset::AssetRecord& other);

        void request(intrnl::GUID id);

        template<typename T>
        AssetHandle<T> get(intrnl::GUID id) const;

    private:
        AssetRegistry();

        bool uniq_GUID(const intrnl::GUID& guid) const;


        std::string asset_dir;

        std::unordered_map<
            intrnl::GUID,
            std::shared_ptr<asset::AssetRecord>,
            intrnl::GUIDHash
        >
        by_guid_;

        std::unordered_map<
            asset::AssetType,
            std::unique_ptr<asset::IAssetLoader>
        > loaders_;
    };
}

#include "rb/registry/AssetRegistry.inl"

#endif //RENDER_ENGINE_ASSETREGISTRY_H