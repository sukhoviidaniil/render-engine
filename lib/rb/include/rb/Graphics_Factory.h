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

#include "ast/RB_Config.h"
#include "rb/View.h"

namespace rb {
    class Graphics_Factory{
        public:

        static std::shared_ptr<View> make_View(const ast::RB_Config &info, const std::string &path);

    private:

        static void Register(
            std::unordered_map<
                ast::RB_Type,
                std::shared_ptr<View> (*)(const ast::RB_Config&, const std::string&)
            > &outMap
        );

        static std::shared_ptr<View> SFML_View(const  ast::RB_Config& info, const std::string& path);
    };
}

#endif //RENDER_ENGINE_GRAPHICS_FACTORY_H