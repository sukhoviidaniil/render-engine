/***************************************************************
 * Project:       Render_Engine
 * File:          UIFactory.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-13
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

#include "layout_engine/UIFactory.h"

#include <functional>

namespace sif::ui {
    using UIFactoryFn = std::function<std::unique_ptr<UIElement>(const Node&)>;

    UIFactory& UIFactory::instance() {
        static UIFactory f;
        return f;
    }

    void UIFactory::register_tag(std::string tag, UIFactoryFn fn)  {
        map_[std::move(tag)] = std::move(fn);
    }

    std::unique_ptr<UIElement> UIFactory::build(const Node &n)  {
        const auto it = map_.find(n.tag);

        if (it == map_.end()) {
            throw std::runtime_error("Unknown tag: " + n.tag);
        }


        auto el = it->second(n);

        for (auto& c : n.children) {
            el->add(build(*c));
        }

        return el;
    }

    UIFactory::UIFactory() {
        register_tag("Element", make_Element);
        register_tag("VBox", make_VBox);
        register_tag("HBox", make_HBox);
        register_tag("Text", make_Text);
        register_tag("Rectangle", make_Rectangle);
    }
}
