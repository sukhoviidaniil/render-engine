/***************************************************************
* Project:       Render_Engine
 * File:          make_element.h
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
#ifndef RENDER_ENGINE_MAKE_ELEMENT_H
#define RENDER_ENGINE_MAKE_ELEMENT_H

#include "add_attribute.h"
#include "layout_engine/Node.h"
#include "layout_engine/elements/LinearLayout.h"
#include "layout_engine/elements/Rectangle.h"
#include "layout_engine/elements/V_HBox.h"


namespace sif::ui {

    inline std::unique_ptr<UIElement> make_Element(const Node& n) {
        auto e = std::make_unique<UIElement>();
        return e;
    }

    inline std::unique_ptr<UIElement> make_VBox(const Node& n) {
        static std::string from = "VBox node";

        auto e = std::make_unique<VBox>();
        VBox *ep = e.get();

        add_attribute_width(n, from, ep);
        add_attribute_height(n, from, ep);
        add_attribute_padding(n, from, ep);
        add_attribute_spacing(n, from, ep);

        return e;
    }

    inline std::unique_ptr<UIElement> make_HBox(const Node& n) {
        static std::string from = "HBox node";

        auto e = std::make_unique<HBox>();
        HBox* ep = e.get();

        add_attribute_width(n, from, ep);
        add_attribute_height(n, from, ep);
        add_attribute_padding(n, from, ep);
        add_attribute_spacing(n, from, ep);

        return e;
    }

    inline std::unique_ptr<UIElement> make_Rectangle(const Node& n) {
        static std::string from = "Rectangle node";
        auto e = std::make_unique<Rectangle>();
        // ReSharper disable once CppJoinDeclarationAndAssignment
        std::string attrbt;

        attrbt = "fill_color";
        if (n.attributes.contains(attrbt)) {
            try {
                e->fill_color = intrnl::Color(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        return e;
    }

    inline std::unique_ptr<UIElement> make_Text(const Node& n) {
        static std::string from = "Text node";
        // ReSharper disable once CppJoinDeclarationAndAssignment
        std::string attrbt;

        attrbt = "guid";
        if (!n.attributes.contains(attrbt)) {
            missing_attribute(from, attrbt);
        }

        intrnl::GUID guid;
        try {
            guid = intrnl::GUID(n.attributes.at(attrbt));
        } catch (const std::exception& e) {
            invalid_attribute(from, attrbt, n.attributes.at(attrbt), e.what());
        }

        rgst::AssetRegistry::instance().request(guid);
        rgst::AssetHandle<asset::Font> font = rgst::AssetRegistry::instance().get<asset::Font>(guid);
        auto e = std::make_unique<Text>(std::move(font));

        attrbt = "color";
        if (n.attributes.contains(attrbt)) {
            try {
                e->color = intrnl::Color(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        attrbt = "fontSize";
        if (n.attributes.contains(attrbt)) {
            try {
                e->fontSize = std::stoi(n.attributes.at("fontSize"));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        attrbt = "inner_text";
        if (n.attributes.contains(attrbt)) {
            try {
                e->text = n.attributes.at(attrbt);
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        return e;
    }
}

#endif