/***************************************************************
* Project:       Render_Engine
 * File:          AssetHandle.inl
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
#include "AssetHandle.h"

namespace view::assets {
    template<class T>
    AssetHandle<T>::AssetHandle() = default;

    template<class T>
    AssetHandle<T>::AssetHandle(std::weak_ptr<AssetRecord> record) : record_(record) {

    }

    template<class T>
    bool AssetHandle<T>::ready() const {
        const auto r = record_.lock();
        return r && r->state == AssetState::Ready && r->asset;
    }

    template<class T>
    T * AssetHandle<T>::get() const {
        auto r = record_.lock();
        if (!r || r->state != AssetState::Ready || !r->asset) {
            return nullptr;
        }
        return static_cast<T*>(r->asset.get());
    }

    template<class T>
    AssetHandle<T>::operator bool() const {
        return ready();
    }

    template<class T>
    GUID AssetHandle<T>::guid() const {
        const auto r = record_.lock();
        return r ? r->guid : GUID{};
    }
}
