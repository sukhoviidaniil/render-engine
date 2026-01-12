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

#include "view/Graphics_Factory.h"

namespace view {
    std::shared_ptr<View> Graphics_Factory::make_View(const infra::ast::View &info, const std::string &path) {
        std::unordered_map<std::string, std::shared_ptr<View>(*)(const infra::ast::View&, const std::string&)> map;
        Register(map);
        std::string type = info.type;
        auto it = map.find(type);
        if (it != map.end()) {
            return it->second(info, path);
        }
        throw std::runtime_error("Unknown view type: " + type);
    }

    void Graphics_Factory::Register(
        std::unordered_map<std::string, std::shared_ptr<View>(*)(const infra::ast::View&, const std::string&)> &outMap
        ) {
        outMap["SFML"] = &Graphics_Factory::SFML_View;

    }

    std::shared_ptr<View> Graphics_Factory::SFML_View(const infra::ast::View& info, const std::string& path) {

    }
}

