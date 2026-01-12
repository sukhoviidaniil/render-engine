/***************************************************************
 * Project:       render-engine
 * File:          window.hpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-21
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
#ifndef RENDER_ENGINE_EV_WINDOW_HPP
#define RENDER_ENGINE_EV_WINDOW_HPP

#include "infra/event/Event.h"

namespace infra::event::window {
    struct Window_Closed{
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Window;
    };

    struct Window_Resized {
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Window;

        std::uint32_t width;
        std::uint32_t height;
    };

    struct Window_FocusGained {
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Window;
    };

    struct Window_FocusLost {
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Window;
    };
}

#endif //RENDER_ENGINE_EV_WINDOW_HPP