/***************************************************************
 * Project:       Render_Engine
 * File:          from_JSON.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-17
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
#ifndef RENDER_ENGINE_RB_FROM_JSON_H
#define RENDER_ENGINE_RB_FROM_JSON_H


#include "infra/io/from_JSON.h"

#include "rb/asset/data/AssetMetaData.h"
#include "rb/asset/data/FontNode.h"
#include "rb/asset/AssetDesc.h"


namespace rb::asset::data {
    inline void from_json(const nlohmann::json& j, AssetMetaData& d) {
        d.guid = intrnl::GUID(infra::io::get_checked<std::string>(j, "guid"));
        d.type = from_string(infra::io::get_checked<std::string>(j, "type"));
        d.asset_name = infra::io::get_checked<std::string>(j, "asset_name");

        d.record_id_to_name = infra::io::get_checked<std::unordered_map<uint32_t, std::string>>(j, "record_id_to_name", d.record_id_to_name);
        d.record_name_to_id.reserve(d.record_id_to_name.size());
        for (const auto& [id, name] : d.record_id_to_name) {
            d.record_name_to_id.emplace(name, id);
        }
    }

    inline void to_json(nlohmann::json& j, const AssetMetaData& d) {
        j = nlohmann::json{
            { "guid", d.guid.string() },
            { "type", to_string(d.type) },
            { "asset_name", d.asset_name },
            { "record_id_to_name", d.record_id_to_name }
        };
    }

    inline void from_json(const nlohmann::json& j, FontNode& d) {
        d.meta = infra::io::get_checked<data::AssetMetaData>(j);
        d.source = infra::io::get_checked<std::string>(j, "source");
    }
}

namespace rb::asset {
    inline void from_json(const nlohmann::json& j, AssetDesc& d) {
        d.meta = infra::io::get_checked<data::AssetMetaData>(j, "meta");
        d.conf_path = infra::io::get_checked<std::string>(j, "conf_path");
    }
    inline void to_json(nlohmann::json& j, const AssetDesc& d) {
        j = nlohmann::json{
            { "meta", d.meta },
            { "conf_path", d.conf_path }
        };
    }

}


#endif //RENDER_ENGINE_RB_FROM_JSON_H
