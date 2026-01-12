/***************************************************************
 * Project:       render-engine
 * File:          Delta_Timer.h
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
#ifndef RENDER_ENGINE_DELTATIMER_H
#define RENDER_ENGINE_DELTATIMER_H

#include <chrono>

namespace infra {

    /**
     * @brief Utility class to measure elapsed time between updates.
     *
     * Uses a steady clock to compute the delta time since the last tick.
     */
    class Delta_Timer {

    public:

        static Delta_Timer& instance();

        /**
         * @brief Returns the time elapsed (in seconds) since the last tick
         *        and updates the internal time point.
         *
         * @return Delta time in seconds.
         */
        float tick();

    private:
        /**
         * @brief Constructs the Delta_Timer and initializes the last time point.
         */
        Delta_Timer();

        using clock = std::chrono::steady_clock;
        clock::time_point last; ///< Last recorded time point
    };
}

#endif //RENDER_ENGINE_DELTATIMER_H