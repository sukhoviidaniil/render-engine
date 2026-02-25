/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-14
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_IASSETLOADER_H
#define RENDER_ENGINE_IASSETLOADER_H

#include "AssetRecord.h"

namespace sif::asset {
    class IAssetLoader {
    public:
        virtual ~IAssetLoader();

        void try_load(AssetRecord& record, const std::string& asset_dir);
    private:

        virtual void load_asset(AssetRecord& record, const std::string& asset_dir) = 0;
    };
}

#endif //RENDER_ENGINE_IASSETLOADER_H