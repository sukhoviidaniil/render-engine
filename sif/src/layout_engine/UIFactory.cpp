/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/

#include "sif/layout_engine/UIFactory.h"

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
