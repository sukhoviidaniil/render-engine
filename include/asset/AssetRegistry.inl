/***************************************************************
* Project:       Render_Engine
 * File:          AssetRegistry.inl
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

#pragma once

#include "asset/AssetRegistry.h"
namespace sif::asset {
    template<typename T>
    AssetHandle<T> AssetRegistry::get(intrnl::GUID id) const {
        auto rec = by_guid_.find(id);
        if (rec != by_guid_.end()) {
            std::weak_ptr<asset::AssetRecord> asset = rec->second;
            AssetHandle<T> handle = AssetHandle<T>(asset);
            return handle;
        }
        // TODO get err
        throw;
    }
}
