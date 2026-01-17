/***************************************************************
 * Project:       Render_Engine
 * File:          RB_Type.h
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
#ifndef RENDER_ENGINE_RB_TYPE_H
#define RENDER_ENGINE_RB_TYPE_H

namespace rb::ast{
    enum struct RB_Type {
        Unknown,
        SFML
    };

    inline RB_Type from_string(const std::string &s) {
        if (s == "SFML") return RB_Type::SFML;
        return RB_Type::Unknown;
    }

    inline std::string to_string(const RB_Type &t) {
        switch (t) {
            case RB_Type::SFML: return "SFML";
            default: return "Unknown";
        }
    }
}

#endif //RENDER_ENGINE_RB_TYPE_H