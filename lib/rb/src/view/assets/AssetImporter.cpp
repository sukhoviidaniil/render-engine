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

#include "rb/registry/AssetImporter.h"

#include "rb/registry/AssetLoader.h"

namespace rb::assets {


    AssetImporter& AssetImporter::instance() {
        static AssetImporter inst;
        return inst;
    }

    AssetImporter::AssetImporter() = default;

    void AssetImporter::load(const std::string& dirpath) {
        std::lock_guard lock(mtx_);

        std::filesystem::path root(dirpath);
        if (!std::filesystem::exists(root) || !std::filesystem::is_directory(root)) {
            return;
        }

        AssetLoader loader = AssetLoader::instance();

        for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            auto desc_opt = loader.load_from_file(entry.path());
            if (desc_opt.has_value()) {
                continue;
            }

            add(std::move(desc_opt.value()));
        }
    }

    void AssetImporter::load_registry(const std::string& filepath) {
        std::lock_guard lock(mtx_);

        std::filesystem::path path(filepath);
        if (!std::filesystem::exists(path)) {
            return;
        }

        AssetLoader loader = AssetLoader::instance();

        auto descs = loader.load_from_config(path);
        for (auto& d : descs) {
            add(std::move(d));
        }
    }

    void AssetImporter::add(AssetDesc desc) {
        intrnl::GUID guid = desc.meta.guid;

        by_guid_.emplace(guid, desc);

        by_asset_name_.emplace(desc.meta.asset_name, std::move(desc));
    }

    AssetDesc AssetImporter::get(const intrnl::GUID id) const {
        auto it = by_guid_.find(id);
        if (it == by_guid_.end())
            throw std::runtime_error("Asset not found by GUID");

        return it->second;
    }

    AssetDesc AssetImporter::get(const std::string &id) const {
        auto it = by_asset_name_.find(id);
        if (it == by_asset_name_.end())
            throw std::runtime_error("Asset not found by name");

        return it->second;
    }


    std::vector<AssetDesc> AssetImporter::get() const {
        std::vector<AssetDesc> out;
        out.reserve(by_guid_.size());

        for (const auto& [_, desc] : by_guid_) {
            out.push_back(desc);
        }
        return out;
    }

}
