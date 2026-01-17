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

#include "rb/assets/IAssetLoader.h"
#include "rb/registry/AssetHandle.h"
#include "rb/registry/AssetRecord.h"

namespace rb::assets {
    class AssetRegistry{
    public:
        static AssetRegistry& instance();

        AssetRegistry(const AssetRegistry&) = delete;
        AssetRegistry& operator=(const AssetRegistry&) = delete;
        AssetRegistry(AssetRegistry&&) = delete;
        AssetRegistry& operator=(AssetRegistry&&) = delete;

        void register_loader(
            intrnl::AssetType type,
            std::unique_ptr<IAssetLoader> loader
            );

        void add_AssetRecord(AssetMetaData meta, std::string conf_path);
        void add_AssetRecord(const AssetRecord& other);

        void request(intrnl::GUID id);

        template<typename T>
        AssetHandle<T> get(intrnl::GUID id) const;

    private:
        AssetRegistry();

        bool uniq_GUID(const intrnl::GUID& guid) const;

        std::unordered_map<
            intrnl::GUID,
            std::shared_ptr<AssetRecord>,
            intrnl::GUIDHash
        >
        by_guid_;

        std::unordered_map<
            intrnl::AssetType,
            std::unique_ptr<IAssetLoader>
        > loaders_;
    };
}

#include "rb/registry/AssetRegistry.inl"

#endif //RENDER_ENGINE_ASSETREGISTRY_H