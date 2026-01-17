/***************************************************************
 * Project:       render-engine
 * File:          Graphics_Factory.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-11-28
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
#ifndef RENDER_ENGINE_GRAPHICS_FACTORY_H
#define RENDER_ENGINE_GRAPHICS_FACTORY_H

#include <memory>

#include "rb/View.h"

#include "infra/ast/rb/View.h"

namespace rb {
    class Graphics_Factory{
        public:

        static std::shared_ptr<View> make_View(const infra::ast::View &info, const std::string &path);

    private:

        static void Register(
            std::unordered_map<
                std::string,
                std::shared_ptr<View> (*)(const infra::ast::View&, const std::string&)
            > &outMap
        );

        static std::shared_ptr<View> SFML_View(const infra::ast::View& info, const std::string& path);
    };
}

#endif //RENDER_ENGINE_GRAPHICS_FACTORY_H