/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETHANDLE_H
#define RENDER_ENGINE_ASSETHANDLE_H
#include <memory>

#include "internal/AssetRecord.h"

namespace sif::asset {
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