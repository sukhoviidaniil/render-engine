/***************************************************************
 * Project:       render-engine
 * File:          Size.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-19
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
#ifndef RENDER_ENGINE_SIZE_H
#define RENDER_ENGINE_SIZE_H
#include <charconv>

namespace rb::intrnl{
    /**
     * @brief Size specification used by the layout engine.
     *
     * Represents how a dimension (width or height) should be resolved:
     * automatically, in absolute pixels, relative percentages, or
     * logical layout units.
     */
    struct Size {
        /**
         * @brief Size interpretation mode.
         */
        enum class Type {
            Auto,       ///< Size is determined automatically by layout rules
            Pixel,       ///< Absolute size in pixels
            Percent,    ///< Size relative to the parent (0–100)
        };

        Type type  = Type::Auto;   ///< Size mode
        float value = 0.f;          ///< Associated value (meaning depends on type)

        /// @brief Automatic size.
        static Size auto_() { return {Type::Auto, 1}; }

        /// @brief Absolute size in pixels.
        static Size px(float v) { return {Type::Pixel, v}; }

        /// @brief Relative size in percent of parent.
        static Size percent(float v) { return {Type::Percent, v}; }

        Size(const Type t, const float v) :type(t), value(v) {}

        explicit Size(std::string_view str) {
            const auto sep = str.find('|');
            if (sep == std::string_view::npos)
                throw std::invalid_argument("Size: invalid format");

            const auto type_sv  = str.substr(0, sep);
            const auto value_sv = str.substr(sep + 1);

            if (type_sv == "AUTO") {
                type = Type::Auto;
                value = 0.f;
                return;
            }

            const std::string tmp(value_sv);

            char* end = nullptr;
            const float v = std::strtof(tmp.c_str(), &end);
            if (end != tmp.c_str() + tmp.size()) {
                throw std::invalid_argument("Size: invalid value");
            }

            if (type_sv == "PX") {
                type = Type::Pixel;
                value = v;
            } else if (type_sv == "PERCENT") {
                type = Type::Percent;
                value = v;
            } else {
                throw std::invalid_argument("Size: unknown type");
            }
        }
    };
}

#endif //RENDER_ENGINE_SIZE_H