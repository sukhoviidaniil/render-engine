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
#include "elemenst/UIElement.h"

namespace view::ui {
    using UIFactoryFn = std::function<std::unique_ptr<UIElement>(const Node&)>;

    class UIFactory {
    public:
        static UIFactory& instance() {
            static UIFactory f;
            return f;
        }

        void register_tag(std::string tag, UIFactoryFn fn) {
            map_[std::move(tag)] = std::move(fn);
        }

        std::unique_ptr<UIElement> build(const Node& n) {
            auto it = map_.find(n.tag);

            if (it == map_.end())
                throw std::runtime_error("Unknown tag: " + n.tag);

            auto el = it->second(n);

            for (auto& c : n.children)
                el->add(build(*c));

            return el;
        }

    private:
        std::unordered_map<
            std::string,
            UIFactoryFn
        > map_;

        UIFactory();
    };
}

#endif //RENDER_ENGINE_UIFACTORY_H