/***************************************************************
 * Project:       Render_Engine
 * File:          AssetRegistry.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-13
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

#include "rb/registry/AssetRegistry.h"

#include <thread>

#include "infra/diagnostics/Logger.h"
#include "infra/diagnostics/LogScope.h"

namespace rb::rgst {
    AssetRegistry& AssetRegistry::instance() {
        static AssetRegistry instance;
        return instance;
    }

    AssetRegistry::AssetRegistry() = default;

    bool AssetRegistry::uniq_GUID(const intrnl::GUID &guid) const {
        if (by_guid_.contains(guid)) {
            return false;
        }
        return true;
    }

    void AssetRegistry::register_loader(const intrnl::AssetType type, std::unique_ptr<asset::IAssetLoader> loader) {
        loaders_[type] = std::move(loader);
    }

    void AssetRegistry::add_AssetRecord(asset::AssetDesc desc) {
        const intrnl::GUID id = desc.meta.guid;
        if (!uniq_GUID(id)) {
            LOG("Double adding  GUID: " + id.string());
            return;
        }
        const auto record_ptr = std::make_shared<asset::AssetRecord>(std::move(desc.meta), std::move(desc.conf_path));
        by_guid_[id] = record_ptr;
    }

    void AssetRegistry::add_AssetRecord(const asset::AssetRecord &other) {
        const intrnl::GUID id = other.get_meta().guid;
        if (!uniq_GUID(id)) {
            LOG("Double adding  GUID: " + id.string());
            return;
        }
        const auto record_ptr = std::make_shared<asset::AssetRecord>(other.get_desc());
        by_guid_[id] = record_ptr;
    }

    void AssetRegistry::request(const intrnl::GUID id) {
        LOG_SCOPE();
        LOG("Requsted GUID: " + id.string());
        auto rec = by_guid_.find(id);
        if (rec != by_guid_.end()) {
            // record exist
            const std::shared_ptr<asset::AssetRecord> record = rec->second;
            const intrnl::AssetState state = record->get_state();
            // If we haven't tried to download it yet, let's try it.
            if (state == intrnl::AssetState::NotRequested) {
                const intrnl::AssetType type = record->get_meta().type;

                // find loader
                auto ld = loaders_.find(type);
                if (ld != loaders_.end()) {
                    record->set_state(intrnl::AssetState::Loading);
                    // Use a raw pointer so as not to move unique_ptr

                    asset::IAssetLoader* loader = ld->second.get();
                    std::weak_ptr<asset::AssetRecord> weak_record = record;

                    std::thread t([loader, weak_record] {
                        if (auto rec = weak_record.lock()) {
                            loader->load(*rec);
                        }
                    });

                    t.detach();
                }else {
                    record->set_state(intrnl::AssetState::Failed);
                    const std::string err = "There is no loader for: " + to_string(type);
                    LOG(err);
                }
            }
            return;
        }
        const std::string err = "Failed to load GUID: " + id.string();
        LOG(err);
        throw std::runtime_error(err);
    }
}