/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-14
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
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