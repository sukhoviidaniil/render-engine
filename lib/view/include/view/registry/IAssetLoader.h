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

namespace view::assets {
    class IAssetLoader {
    public:
        virtual ~IAssetLoader() = default;

        void load(AssetRecord& record)  {
            try_load(record);
        }

    private:
        void try_load(AssetRecord& record) {
            LOG_SCOPE();
            LOG("Start loading asset: " + record.meta.asset_name);
            try {
                load_asset(record);
                record.set_state(intrnl::AssetState::Ready);
                LOG("Successfully loaded asset: " + record.meta.asset_name);
            } catch (const std::exception& e) {
                record.set_state(intrnl::AssetState::Failed);
                LOG("Failed to load asset: " + record.meta.asset_name + " | Exception: " + e.what());
            } catch (...) {
                record.set_state(intrnl::AssetState::Failed);
                LOG("Failed to load asset: " + record.meta.asset_name + " | Unknown error");
            }
        }

        virtual void load_asset(AssetRecord& record) = 0;
    };
}

#endif //RENDER_ENGINE_IASSETLOADER_H