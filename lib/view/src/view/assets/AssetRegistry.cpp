/***************************************************************
 * Project:       Render_Engine
 * File:          AssetRegistry.cpp
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

#include "../../../include/view/registry/AssetRegistry.h"

namespace view::assets {
    AssetRegistry& AssetRegistry::instance() {
        static AssetRegistry instance;
        return instance;
    }
    AssetRegistry::AssetRegistry() = default;

    void AssetRegistry::register_loader(const AssetType type, std::unique_ptr<IAssetLoader> loader) {
        loaders_[type] = std::move(loader);
    }

    void AssetRegistry::request(const GUID id) {
        auto rec = by_guid_.find(id);
        if (rec != by_guid_.end()) {
            // TODO request load
        }else {
            // TODO request load err
            throw;
        }
    }

    std::optional<GUID> AssetRegistry::get(const std::string &display_name) const {
        auto rec = by_display_name_.find(display_name);
        if (rec != by_display_name_.end()) {
            return rec->second;
        }
        return std::nullopt;
    }

}
