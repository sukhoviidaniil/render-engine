/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-02-01
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "sif/asset/internal/AssetRecord.h"

namespace sif::asset {
    AssetRecord::AssetRecord(AssetDesc d)
        : desc(std::move(d)) {

    }

    AssetRecord::AssetRecord(data::AssetMetaData meta, std::string conf_path)
        : AssetRecord(AssetDesc{std::move(conf_path), std::move(meta)}) {

    }

    AssetDesc AssetRecord::get_desc() const {
        return desc;
    }

    const data::AssetMetaData & AssetRecord::get_meta() const {
        return desc.meta;
    }

    const std::string & AssetRecord::get_conf_path() const {
        return desc.conf_path;
    }

    AssetState AssetRecord::get_state() const  {
        std::lock_guard lock(mtx_);
        return state_;
    }

    void AssetRecord::set_state(AssetState s) {
        std::lock_guard lock(mtx_);
        state_ = s;
    }

    std::shared_ptr<void> AssetRecord::get_data() const {
        std::lock_guard lock(mtx_);
        return data_;
    }

    void AssetRecord::set_data(std::shared_ptr<void> d)  {
        std::lock_guard lock(mtx_);
        data_ = std::move(d);
    }
}
