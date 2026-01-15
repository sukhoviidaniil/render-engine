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

#include "view/internal/AssetType.h"
#include "view/registry/assets_data/AssetDataVisitor.h"


namespace view::assets {
    struct AssetDataNode {
        virtual ~AssetDataNode() = default;

        virtual void accept(AssetDataVisitor &v) const {
        }

        virtual AssetType type() const {
            return AssetType::Undefined;
        }

        int guid = -1;
        std::string asset_name = "NONE";
        std::string path = "NONE";
    };
}

#endif //RENDER_ENGINE_METAASSETDATA_H