/***************************************************************
 * Project:       Render_Engine
 * File:          AssetType.h
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
#ifndef RENDER_ENGINE_ASSETTYPE_H
#define RENDER_ENGINE_ASSETTYPE_H

#include <string>

namespace sif::asset {
    enum struct AssetType {
        Undefined,
        Font,
        SpriteSingle,
        SpriteAtlas,
        SpriteGrid
    };

    inline AssetType from_string(const std::string& s) {
        if (s == "Font")            return AssetType::Font;
        if (s == "SpriteSingle")    return AssetType::SpriteSingle;
        if (s == "SpriteAtlas")     return AssetType::SpriteAtlas;
        if (s == "SpriteGrid")      return AssetType::SpriteGrid;
        return AssetType::Undefined;
    }

    inline std::string to_string(const AssetType& t){
        switch (t) {
            case AssetType::Font :          return "Font";
            case AssetType::SpriteSingle :  return "SpriteSingle";
            case AssetType::SpriteAtlas :   return "SpriteAtlas";
            case AssetType::SpriteGrid :    return "SpriteGrid";
            default: return "Undefined";
        }
    }
}

#endif //RENDER_ENGINE_ASSETTYPE_H