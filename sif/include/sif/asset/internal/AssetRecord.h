/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETRECORD_H
#define RENDER_ENGINE_ASSETRECORD_H

#include <memory>
#include <string>

#include "AssetDesc.h"
#include "AssetState.h"

namespace sif::asset {

    struct AssetRecord {

        AssetRecord(AssetRecord&&) noexcept = delete;
        AssetRecord& operator=(AssetRecord&&) noexcept = delete;

        AssetRecord(const AssetRecord&) = delete;
        AssetRecord& operator=(const AssetRecord&) = delete;

        explicit AssetRecord(AssetDesc d);

        AssetRecord(data::AssetMetaData meta, std::string conf_path);

        AssetDesc get_desc() const;
        const data::AssetMetaData& get_meta() const;
        const std::string& get_conf_path() const;

        AssetState get_state() const;

        void set_state(AssetState s);
        std::shared_ptr<void> get_data() const;

        void set_data(std::shared_ptr<void> d);

    private:
        AssetDesc desc;
        mutable std::mutex mtx_;

        AssetState state_ = AssetState::NotRequested;
        std::shared_ptr<void> data_;
    };
}

#endif //RENDER_ENGINE_ASSETRECORD_H