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
#include <utility>

#include "rb/asset/AssetDesc.h"
#include "rb/asset/AssetState.h"

namespace rb::asset {


    struct AssetRecord {

        explicit AssetRecord(AssetDesc d)
        : desc(std::move(d)) {

        }

        AssetRecord(data::AssetMetaData meta, std::string conf_path)
            : AssetRecord(AssetDesc{std::move(meta), std::move(conf_path)}) {

        }

        AssetRecord(AssetRecord&&) noexcept = delete;
        AssetRecord& operator=(AssetRecord&&) noexcept = delete;

        AssetRecord(const AssetRecord&) = delete;
        AssetRecord& operator=(const AssetRecord&) = delete;

        AssetDesc get_desc() const{
            return desc;
        }

        const data::AssetMetaData& get_meta() const{
            return desc.meta;
        }
        const std::string& get_conf_path() const{
            return desc.conf_path;
        }

        asset::AssetState get_state() const {
            std::lock_guard lock(mtx_);
            return state_;
        }

        void set_state(asset::AssetState s) {
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

    private:
        AssetDesc desc;
        mutable std::mutex mtx_;

        asset::AssetState state_ = asset::AssetState::NotRequested;
        std::shared_ptr<void> data_;
    };
}

#endif //RENDER_ENGINE_ASSETRECORD_H