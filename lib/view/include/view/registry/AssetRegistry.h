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
#include <optional>
#include <unordered_map>

#include "AssetHandle.h"
#include "AssetRecord.h"
#include "IAssetLoader.h"

namespace view::assets {
    class AssetRegistry{
    public:
        static AssetRegistry& instance();

        AssetRegistry(const AssetRegistry&) = delete;
        AssetRegistry& operator=(const AssetRegistry&) = delete;
        AssetRegistry(AssetRegistry&&) = delete;
        AssetRegistry& operator=(AssetRegistry&&) = delete;

        void register_loader(
            AssetType type,
            std::unique_ptr<IAssetLoader> loader
            );

        void request(GUID id);

        std::optional<GUID> get(const std::string &display_name) const;

        template<typename T>
        AssetHandle<T> get(GUID id) const;

    private:
        AssetRegistry();

        std::unordered_map<
            std::string,
            GUID
        >
        by_display_name_;

        std::unordered_map<
            GUID,
            std::shared_ptr<AssetRecord>,
            GUIDHash
        >
        by_guid_;

        std::unordered_map<
            AssetType,
            std::unique_ptr<IAssetLoader>
        > loaders_;
    };
}

#include "view/assets/AssetRegistry.inl"

#endif //RENDER_ENGINE_ASSETREGISTRY_H