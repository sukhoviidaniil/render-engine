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
#include "rb/registry/AssetRegistry.h"

namespace rb::ui {
    inline void missing_attribute(const std::string& from, const std::string &attribute) {
        throw std::runtime_error(from + ": missing required attribute '" +attribute+ "'");
    }
    inline void invalid_attribute(const std::string& from, const std::string &attribute, const std::string &at, const char *what) {
        throw std::runtime_error(
            from + ": invalid " + attribute + " value '" + at + "': " + what
        );
    }

    inline std::unique_ptr<UIElement> make_Element(const Node& n) {
        auto e = std::make_unique<UIElement>();
        return e;
    }
    inline std::unique_ptr<UIElement> make_VBox(const Node& n) {
        static std::string from = "VBox node";
        // ReSharper disable once CppJoinDeclarationAndAssignment
        std::string attrbt;

        auto e = std::make_unique<VBox>();

        attrbt = "spacing";
        if (n.attributes.contains(attrbt)) {
            try {
                e->spacing = std::stof(n.attributes.at(attrbt ));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }
        attrbt = "padding";
        if (n.attributes.contains(attrbt)) {
            try {
                e->padding = {std::stof(n.attributes.at("padding")), std::stof(n.attributes.at("padding"))};
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }
        return e;
    }

    inline std::unique_ptr<UIElement> make_HBox(const Node& n) {
        static std::string from = "HBox node";
        // ReSharper disable once CppJoinDeclarationAndAssignment
        std::string attrbt;

        auto e = std::make_unique<HBox>();

        attrbt = "spacing";
        if (n.attributes.contains(attrbt)) {
            try {
                e->spacing = std::stof(n.attributes.at(attrbt ));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }
        attrbt = "padding";
        if (n.attributes.contains(attrbt)) {
            try {
                e->padding = {std::stof(n.attributes.at("padding")), std::stof(n.attributes.at("padding"))};
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }
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

        return e;
    }
}
