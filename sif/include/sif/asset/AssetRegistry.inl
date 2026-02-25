/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#pragma once

#include "AssetRegistry.h"

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
