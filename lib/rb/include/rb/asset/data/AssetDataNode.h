/***************************************************************
 * Project:       Render_Engine
 * File:          MetaAssetData.h
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
#ifndef RENDER_ENGINE_METAASSETDATA_H
#define RENDER_ENGINE_METAASSETDATA_H
#include <string>

#include "rb/asset/data/AssetMetaData.h"


namespace rb::asset::data {
    struct  AssetDataNode {
        std::string source;
        AssetMetaData meta;
    };
}

#endif //RENDER_ENGINE_METAASSETDATA_H