/***************************************************************
 * Project:         Render_Engine
 * File:            attribute_check.h
 *
 * Author:          Sukhovii Daniil
 * Contact:
 * Email:           Sukhovii Daniil
 * Created:         2026-02-08
 *
 * Description:     []
 *
 * Disclaimer:
 *  This file is part of Render_Engine.
 *  Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ATTRIBUTE_CHECK_H
#define RENDER_ENGINE_ATTRIBUTE_CHECK_H

#include <stdexcept>
#include <string>


namespace sif::ui {
    inline void missing_attribute(const std::string& from, const std::string &attribute) {
        throw std::runtime_error(from + ": missing required attribute '" +attribute+ "'");
    }
    inline void invalid_attribute(const std::string& from, const std::string &attribute, const std::string &at, const char *what) {
        throw std::runtime_error(
            from + ": invalid " + attribute + " value '" + at + "': " + what
        );
    }
}

#endif //RENDER_ENGINE_ATTRIBUTE_CHECK_H