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

namespace view {
    enum struct AssetType {
        Undefined,
        Font,
        Sprite
    };

    inline AssetType from_string(const std::string& s) {
        if (s == "Undefined")       return AssetType::Undefined;
        if (s == "Font")            return AssetType::Font;
        if (s == "Sprite")          return AssetType::Sprite;
        return AssetType::Undefined;
    }

    inline std::string to_string(const AssetType& t){
        switch (t) {
            case AssetType::Font :      return "Font";
            case AssetType::Sprite :    return "Sprite";
            default:                    return "Undefined";
        }
    }
}

#endif //RENDER_ENGINE_ASSETTYPE_H