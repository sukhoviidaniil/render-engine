/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETREGISTRY_H
#define RENDER_ENGINE_ASSETREGISTRY_H

#include <unordered_map>

#include "internal/AssetRecord.h"
#include "internal/IAssetLoader.h"
#include "AssetHandle.h"


namespace sif::asset {
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

#include "AssetRegistry.inl"

#endif //RENDER_ENGINE_ASSETREGISTRY_H