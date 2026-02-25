/***************************************************************
 * Project:       Render_Engine
 * File:          SFML_Font_AssetLoader.h
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
#ifndef RENDER_ENGINE_SFML_SFML_FONT_ASSETLOADER_H
#define RENDER_ENGINE_SFML_SFML_FONT_ASSETLOADER_H

#include "sif/asset/IAssetLoader.h"

namespace sif::sfml {
    class SFML_Font_AssetLoader : public asset::IAssetLoader{

        void load_asset(asset::AssetRecord& record, const std::string& asset_dir) override;
    };
}

#endif //RENDER_ENGINE_SFML_SFML_FONT_ASSETLOADER_H