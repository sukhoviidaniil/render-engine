/***************************************************************
 * Project:       Render_Engine
 * File:          IAssetLoader.h
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
#ifndef RENDER_ENGINE_IASSETLOADER_H
#define RENDER_ENGINE_IASSETLOADER_H

#include "infra/diagnostics/Logger.h"
#include "infra/diagnostics/LogScope.h"
#include "AssetRecord.h"

namespace rb::asset {
    class IAssetLoader {
    public:
        virtual ~IAssetLoader() = default;

        void load(AssetRecord& record)  {
            try_load(record);
        }

    private:
        void try_load(AssetRecord& record) {
            LOG_SCOPE();
            const std::string& asset_name = record.get_meta().asset_name;
            LOG("Start loading asset: " + asset_name);
            try {
                load_asset(record);
                record.set_state(intrnl::AssetState::Ready);
                LOG("Successfully loaded asset: " + asset_name);
            } catch (const std::exception& e) {
                record.set_state(intrnl::AssetState::Failed);
                LOG("Failed to load asset: " + asset_name + " | Exception: " + e.what());
            } catch (...) {
                record.set_state(intrnl::AssetState::Failed);
                LOG("Failed to load asset: " + asset_name + " | Unknown error");
            }
        }

        virtual void load_asset(AssetRecord& record) = 0;
    };
}

#endif //RENDER_ENGINE_IASSETLOADER_H