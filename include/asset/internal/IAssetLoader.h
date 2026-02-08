/***************************************************************
 * Project:       Render_Engine
 * File:          IAssetLoader.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-14
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
#ifndef RENDER_ENGINE_IASSETLOADER_H
#define RENDER_ENGINE_IASSETLOADER_H

#include "asset/internal/AssetRecord.h"

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