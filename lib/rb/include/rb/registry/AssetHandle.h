/***************************************************************
 * Project:       Render_Engine
 * File:          AssetHandle.h
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
#ifndef RENDER_ENGINE_ASSETHANDLE_H
#define RENDER_ENGINE_ASSETHANDLE_H
#include <memory>

#include "rb/registry/AssetRecord.h"

namespace rb::assets {
    template<class T>
    class AssetHandle {
    public:
        AssetHandle();
        explicit AssetHandle(std::weak_ptr<AssetRecord> record);

        [[nodiscard]] bool ready() const;

        T* get() const;
        explicit operator bool() const;
        [[nodiscard]] intrnl::GUID guid() const;

    private:
        std::weak_ptr<AssetRecord> record_;
    };
}

#include "AssetHandle.inl"

#endif //RENDER_ENGINE_ASSETHANDLE_H