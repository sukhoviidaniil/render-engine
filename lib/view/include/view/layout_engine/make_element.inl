/***************************************************************
* Project:       Render_Engine
 * File:          make_element.inl
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

#pragma once

#include "elements/Rectangle.h"
#include "elements/Text.h"
#include "elements/V_HBox.h"

namespace view::ui {
    inline std::unique_ptr<UIElement> make_Element(const Node& n) {
        auto e = std::make_unique<UIElement>();
        return e;
    }
    inline std::unique_ptr<UIElement> make_VBox(const Node& n) {
        auto v = std::make_unique<VBox>();
        if (n.attributes.contains("spacing")) {
            v->spacing = std::stof(n.attributes.at("spacing"));
        }
        if (n.attributes.contains("padding")) {
            v->padding = {std::stof(n.attributes.at("padding")), std::stof(n.attributes.at("padding"))};
        }
        return v;

    }
    inline std::unique_ptr<UIElement> make_HBox(const Node& n) {
        auto h = std::make_unique<HBox>();
        if (n.attributes.contains("spacing")) {
            h->spacing = std::stof(n.attributes.at("spacing"));
        }
        if (n.attributes.contains("padding")) {
            h->padding = {std::stof(n.attributes.at("padding")), std::stof(n.attributes.at("padding"))};
        }
        return h;
    }
    inline std::unique_ptr<UIElement> make_Text(const Node& n) {
        auto e = std::make_unique<Text>();
        return e;
    }
    inline std::unique_ptr<UIElement> make_Rectangle(const Node& n) {
        auto e = std::make_unique<Rectangle>();
        return e;
    }

}
