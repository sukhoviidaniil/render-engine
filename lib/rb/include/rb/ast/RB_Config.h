/***************************************************************
 * Project:       Render_Engine
 * File:          RB_Config.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-17
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
#ifndef RENDER_ENGINE_RB_CONFIG_H
#define RENDER_ENGINE_RB_CONFIG_H
#include "RB_Type.h"

namespace rb::ast {
    struct RB_Config {
        RB_Type type;
        std::string window_name;
        unsigned int window_width = 0; ///< Width of the window
        unsigned int window_height = 0; ///< Height of the window
        int fps = 30; ///< Frames per second
    };
}

#endif //RENDER_ENGINE_RB_CONFIG_H