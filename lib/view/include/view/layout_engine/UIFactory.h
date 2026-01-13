/***************************************************************
 * Project:       Render_Engine
 * File:          UIFactory.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-12
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
#ifndef RENDER_ENGINE_UIFACTORY_H
#define RENDER_ENGINE_UIFACTORY_H

#include "Node.h"
#include "view/layout_engine/elements/UIElement.h"

namespace view::ui {

    class UIFactory {
    public:
        static UIFactory& instance();

        void register_tag(std::string tag, std::function<std::unique_ptr<UIElement>(const Node&)> fn);

        std::unique_ptr<UIElement> build(const Node& n);

    private:
        std::unordered_map<
            std::string,
            std::function<std::unique_ptr<UIElement>(const Node&)>
        > map_;

        UIFactory();
    };
}

#include "view/layout_engine/make_element.inl"

#endif //RENDER_ENGINE_UIFACTORY_H