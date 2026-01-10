/***************************************************************
 * Project:       render-engine
 * File:          Status.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-23
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of render-engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_STATUS_H
#define RENDER_ENGINE_STATUS_H

namespace infra {
    enum class Status {
        Dead,
        Alive,
        Powered,
        Weak,
        SlightlyWeak
    };
}

#endif //RENDER_ENGINE_STATUS_H