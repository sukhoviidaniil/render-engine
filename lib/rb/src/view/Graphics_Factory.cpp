/***************************************************************
 * Project:       render-engine
 * File:          Graphics_Factory.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-02
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

#include "rb/Graphics_Factory.h"

namespace rb {
    std::shared_ptr<Renderer> Graphics_Factory::make_View(const ast::RB_Config &info, const std::string &path) {
        std::unordered_map<ast::RB_Type, std::shared_ptr<Renderer>(*)(const ast::RB_Config&, const std::string&)> map;
        Register(map);
        ast::RB_Type type = info.type;
        auto it = map.find(type);
        if (it != map.end()) {
            return it->second(info, path);
        }
        throw std::runtime_error("Unknown rb type: " + to_string(type));
    }

    void Graphics_Factory::Register(
        std::unordered_map<ast::RB_Type, std::shared_ptr<Renderer>(*)(const ast::RB_Config&, const std::string&)> &outMap
        ) {
        outMap[ast::RB_Type::SFML] = &Graphics_Factory::SFML_View;

    }

    std::shared_ptr<Renderer> Graphics_Factory::SFML_View(const ast::RB_Config& info, const std::string& path) {
        // TODO
    }
}

