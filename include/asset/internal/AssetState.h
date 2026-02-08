/***************************************************************
 * Project:       Render_Engine
 * File:          AssetState.h
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
#ifndef RENDER_ENGINE_ASSETSTATE_H
#define RENDER_ENGINE_ASSETSTATE_H

namespace sif::asset {
    enum class AssetState {
        NotRequested,
        Loading,
        Ready,
        Failed
    };
}

#endif //RENDER_ENGINE_ASSETSTATE_H