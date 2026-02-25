/***************************************************************
 * Project:       render-engine
 * File:          Delta_Timer.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-11-15
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

#include "infra/internal/Delta_Timer.h"

namespace infra::intr {

    Delta_Timer & Delta_Timer::instance() {
        static Delta_Timer inst;
        return inst;
    }

    Delta_Timer::Delta_Timer() {
        last = clock::now();
    }

    float Delta_Timer::tick()  {
        const auto now = clock::now();
        const std::chrono::duration<float> diff = now - last;
        last = now;
        return diff.count(); // seconds
    }
}
