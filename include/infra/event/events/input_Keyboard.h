/***************************************************************
 * Project:       render-engine
 * File:          input.h
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
#ifndef RENDER_ENGINE_INPUT_H
#define RENDER_ENGINE_INPUT_H
#include <cstdint>


#include "infra/event/Event.h"

namespace infra::event::input {
    enum class Key : std::uint16_t {
        Unknown,
        W, A, S, D,
        Escape,
        Enter,
        Space,
        Left, Right, Up, Down,
    };

    struct KeyPressed {
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Input;
        Key key;
        bool alt;
        bool control;
        bool shift;
        bool system;
    };

    struct KeyReleased {
        static constexpr infra::event::EventMask mask =
            infra::event::EventMask::Input;
        Key key;
    };
}

#endif //RENDER_ENGINE_INPUT_H