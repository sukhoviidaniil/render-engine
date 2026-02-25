/***************************************************************
 * Project:       Render_Engine
 * File:          AssetDataLoader.cpp
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

#include "asset/internal/data/AssetDataLoader.h"

#include "internal/from_JSON.h"

namespace sif::asset::data {

    AssetDataLoader & AssetDataLoader::instance() {
        static AssetDataLoader instance;
        return instance;
    }

    std::unique_ptr<AssetDataNode> AssetDataLoader::load_from_file(const std::filesystem::path &path) {
        const nlohmann::json& j = infra::io::get_json_data(path);
        const asset::AssetType type = from_string(infra::io::get_checked<std::string>(j, "type"));
        switch (type) {
            case AssetType::Font:
                return load_Font_from_file(path);
            default: return nullptr;
        }

    }

    void AssetDataLoader::save_Meta(const std::filesystem::path &path, data::AssetMetaData& meta) {
        switch (meta.type) {
            case AssetType::Font:
                save_Meta_Font(path, meta);
                break;
            default: break;
        }
    }


    std::unique_ptr<FontNode> AssetDataLoader::load_Font_from_file(const std::filesystem::path &path) {
        const nlohmann::json& j = infra::io::get_json_data(path);
        auto t = infra::io::get_checked<FontNode>(j);

        return std::make_unique<FontNode>(t);
    }

    void AssetDataLoader::save_Meta_Font(const std::filesystem::path &path, data::AssetMetaData& meta) {
        nlohmann::json j = infra::io::get_json_data(path);

        j["guid"] = meta.guid.string();
        j["asset_name"] = meta.asset_name;

        std::ofstream out(path, std::ios::binary | std::ios::trunc);
        if (!out) {
            throw std::runtime_error("Failed to open file for writing: " + path.string());
        }

        out << j.dump(4);
    }

    AssetDataLoader::AssetDataLoader() = default;

}
