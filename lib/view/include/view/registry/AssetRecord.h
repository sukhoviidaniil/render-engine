/***************************************************************
 * Project:       Render_Engine
 * File:          AssetRecord.h
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
#ifndef RENDER_ENGINE_ASSETRECORD_H
#define RENDER_ENGINE_ASSETRECORD_H

#include <memory>
#include <string>

#include "assets_data/AssetMetaData.h"
#include "view/internal/AssetState.h"

namespace view::assets {
    struct AssetRecord {
        AssetRecord(AssetMetaData meta_, std::string conf_path_)
        : meta(std::move(meta_)), conf_path(std::move(conf_path_)) {

        }

        AssetRecord(AssetRecord&&) noexcept = delete;
        AssetRecord& operator=(AssetRecord&&) noexcept = delete;

        AssetRecord(const AssetRecord&) = delete;
        AssetRecord& operator=(const AssetRecord&) = delete;


        intrnl::AssetState get_state() const {
            std::lock_guard lock(mtx_);
            return state_;
        }

        void set_state(intrnl::AssetState s) {
            std::lock_guard lock(mtx_);
            state_ = s;
        }
        std::shared_ptr<void> get_data() const {
            std::lock_guard lock(mtx_);
            return data_;
        }

        void set_data(std::shared_ptr<void> d) {
            std::lock_guard lock(mtx_);
            data_ = std::move(d);
        }

        AssetMetaData meta;
        std::string conf_path;

    private:
        mutable std::mutex mtx_;

        intrnl::AssetState state_ = intrnl::AssetState::NotRequested;
        std::shared_ptr<void> data_;
    };
}

#endif //RENDER_ENGINE_ASSETRECORD_H