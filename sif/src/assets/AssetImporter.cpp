/***************************************************************
 * Project:       Render_Engine
 * File:          AssetImporter.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-16
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

#include "asset/internal/AssetImporter.h"

#include "asset/internal/data/AssetDataLoader.h"
#include "internal/from_JSON.h"
#include "asset/AssetRegistry.h"

namespace sif::asset {

    AssetImporter& AssetImporter::instance() {
        static AssetImporter inst;
        return inst;
    }

    AssetImporter::AssetImporter() = default;

    void AssetImporter::load_from_path(const std::string& dirpath) {
        std::lock_guard lock(mtx_);

        std::filesystem::path root(dirpath);
        if (!std::filesystem::exists(root) || !std::filesystem::is_directory(root)) {
            return;
        }

        for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) {
            if (!entry.is_regular_file()) {
                continue;
            }
            if (entry.path().extension() != ".json" || !entry.path().filename().string().ends_with(".asset.json")) {
                continue; // read only *.asset.json
            }


            auto data_node = data::AssetDataLoader::load_from_file(entry.path());
            if (data_node == nullptr) {
                continue;
            }

            auto rel_path = entry.path().lexically_relative(root);

            asset::AssetDesc desc(
                rel_path.string(),
                data_node->meta
                );

            add(desc);

            data::AssetDataLoader::save_Meta(entry.path(), desc.meta);

        }
    }

    void AssetImporter::save_in_file(const std::string &filepath) {
        nlohmann::json j = nlohmann::json::array();

        for (const auto& [guid, desc] : by_guid_) {
            j.push_back(desc); // relies on to_json(AssetDesc)
        }

        std::ofstream out(filepath, std::ios::binary);
        if (!out) {
            throw std::runtime_error("Failed to open file: " + filepath);
        }

        out << j.dump(4);
    }

    void AssetImporter::load_from_file(const std::string& filepath) {
        std::lock_guard lock(mtx_);

        std::filesystem::path path(filepath);
        if (!std::filesystem::exists(path)) {
            return; // file not found — do not load anything
        }

        std::ifstream in(path, std::ios::binary);
        if (!in) {
            throw std::runtime_error("Failed to open file: " + filepath);
        }

        nlohmann::json j;
        in >> j;

        if (!j.is_array()) {
            throw std::runtime_error("Invalid asset file format: expected JSON array");
        }

        by_guid_.clear();
        by_asset_name_.clear();
        guids_.clear();

        for (const auto& jd : j) {
            auto desc = infra::io::get_checked<AssetDesc>(jd);
            add(desc);
        }
    }

    void AssetImporter::add(AssetDesc& desc) {
        intrnl::GUID& g = desc.meta.guid;
        std::string asset_name = desc.meta.asset_name;
        auto it= by_asset_name_.find(asset_name);
        if (it != by_asset_name_.end()) {
            intrnl::GUID& existing = it->second.meta.guid;
            if (g != existing) {
                LOG(
                    "Asset_name - " + asset_name +
                    " | GUID - " + g.string() +
                    " collides with GUID - " + existing.string()
                    );
            }
            return;
        }

        if (guids_.contains(g)) {
            g = intrnl::generate_guid(guids_);
        }

        guids_.insert(g);
        by_guid_.emplace(g, desc);
        by_asset_name_.emplace(asset_name, desc);
    }


    void AssetImporter::load_in_registry() {
        for (const auto& [guid, desc] : by_guid_) {
            AssetRegistry::instance().add_AssetRecord(desc);
        }
    }

    AssetDesc AssetImporter::get(const std::string &id) const {
        auto it = by_asset_name_.find(id);
        if (it == by_asset_name_.end()) {
            throw std::runtime_error("Asset not found by name");
        }
        return it->second;
    }

}

