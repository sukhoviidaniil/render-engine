/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-17
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ASSETDESC_H
#define RENDER_ENGINE_ASSETDESC_H

#include <string>
#include <utility>

#include "data/AssetMetaData.h"

namespace sif::asset {
    struct AssetDesc {
        AssetDesc() = default;
        AssetDesc(std::string c, data::AssetMetaData m) : conf_path(std::move(c)), meta(std::move(m)) {

        }

        std::string conf_path;
        data::AssetMetaData meta;
    };
}

#endif //RENDER_ENGINE_ASSETDESC_H