/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-01-13
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_MAKE_ELEMENT_H
#define RENDER_ENGINE_MAKE_ELEMENT_H

#include "add_attribute.h"
#include "sif/internal/GUID.h"
#include "sif/asset/AssetRegistry.h"
#include "sif/asset/internal/Font.h"
#include "sif/layout_engine/Node.h"
#include "sif/layout_engine/elements/LinearLayout.h"
#include "sif/layout_engine/elements/Rectangle.h"
#include "sif/layout_engine/elements/Sprite.h"
#include "sif/layout_engine/elements/Button.h"
#include "sif/layout_engine/elements/Menu.h"
#include "sif/layout_engine/elements/Text.h"
#include "sif/layout_engine/elements/V_HBox.h"


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

        asset::AssetRegistry::instance().request(guid);
        asset::AssetHandle<asset::Font> font = asset::AssetRegistry::instance().get<asset::Font>(guid);
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

    inline std::unique_ptr<UIElement> make_Sprite(const Node& n) {
        static std::string from = "Sprite node";
        std::string attrbt;

        attrbt = "sprite";
        if (!n.attributes.contains(attrbt)) {
            missing_attribute(from, attrbt);
        }
        const std::string sprite_name = n.attributes.at(attrbt);

        float sprite_width = 0.f;
        attrbt = "sprite_width";
        if (n.attributes.contains(attrbt)) {
            try {
                sprite_width = std::stof(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        float sprite_height = 0.f;
        attrbt = "sprite_height";
        if (n.attributes.contains(attrbt)) {
            try {
                sprite_height = std::stof(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        return std::make_unique<Sprite>(sprite_name, sprite_width, sprite_height);
    }

    inline std::unique_ptr<UIElement> make_Button(const Node& n) {
        static std::string from = "Button node";
        auto e = std::make_unique<Button>();
        Button* ep = e.get();

        add_attribute_width(n, from, ep);
        add_attribute_height(n, from, ep);

        std::string attrbt;

        attrbt = "unselected_color";
        if (n.attributes.contains(attrbt)) {
            try {
                e->unselected_color = intrnl::Color(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        attrbt = "selected_color";
        if (n.attributes.contains(attrbt)) {
            try {
                e->selected_color = intrnl::Color(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        attrbt = "transition_duration";
        if (n.attributes.contains(attrbt)) {
            try {
                e->transition_duration_seconds = std::stof(n.attributes.at(attrbt));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attrbt, n.attributes.at(attrbt), ex.what());
            }
        }

        attrbt = "selected";
        if (n.attributes.contains(attrbt) && n.attributes.at(attrbt) == "true") {
            e->select();
        }

        return e;
    }

    inline std::unique_ptr<UIElement> make_Menu(const Node& n) {
        static std::string from = "Menu node";

        auto e = std::make_unique<Menu>();
        Menu* ep = e.get();

        add_attribute_width(n, from, ep);
        add_attribute_height(n, from, ep);
        add_attribute_padding(n, from, ep);
        add_attribute_spacing(n, from, ep);

        return e;
    }
}

#endif