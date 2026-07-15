/***************************************************************
* Author:           Daniil Sukhovii
* Email:            sukhovii.daniil@gmail.com
* Created:          2026-02-08
*
* License:
*       c. 2026 Daniil Sukhovii. All rights reserved.
*       Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_ADD_ATTRIBUTE_H
#define RENDER_ENGINE_ADD_ATTRIBUTE_H
#include <cstdint>

#include "attribute_check.h"
#include "sif/internal/Size.h"
#include "sif/layout_engine/Node.h"
#include "sif/layout_engine/elements/LinearLayout.h"
#include "sif/layout_engine/elements/UIElement.h"


namespace sif::ui {


    inline void add_attribute_width(const Node& n, const std::string& from, UIElement * element) {
        const std::string attribute = "width";
        if (n.attributes.contains(attribute)) {
            try {
                element->width = intrnl::Size(n.attributes.at(attribute));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attribute, n.attributes.at(attribute), ex.what());
            }
        }
    }

    inline void add_attribute_height(const Node& n, const std::string& from, UIElement * element) {
        const std::string attribute = "height";
        if (n.attributes.contains(attribute)) {
            try {
                element->height = intrnl::Size(n.attributes.at(attribute));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attribute, n.attributes.at(attribute), ex.what());
            }
        }
    }

    /**
     * @brief Applies the optional "name" attribute, used by UIElement::find_by_name.
     *
     * Common to every element type (unlike width/height/padding, which
     * only some elements interpret), so UIFactory::build applies this
     * once for every tag rather than each make_* function repeating it.
     */
    inline void add_attribute_name(const Node& n, UIElement * element) {
        const std::string attribute = "name";
        if (n.attributes.contains(attribute)) {
            element->name = n.attributes.at(attribute);
        }
    }

    /**
     * @brief Applies the optional "id" attribute, used by UIElement::find_by_id
     * and by ui::Menu::set_active.
     *
     * Common to every element type, applied once by UIFactory::build.
     */
    inline void add_attribute_id(const Node& n, const std::string& from, UIElement * element) {
        const std::string attribute = "id";
        if (n.attributes.contains(attribute)) {
            try {
                element->id = intrnl::RecordID(static_cast<std::uint32_t>(std::stoul(n.attributes.at(attribute))));
            } catch (const std::exception& ex) {
                invalid_attribute(from, attribute, n.attributes.at(attribute), ex.what());
            }
        }
    }


    inline void add_attribute_padding(const Node& n, const std::string& from, UIElement * element) {
        const std::string attribute = "padding";
        if (n.attributes.contains(attribute)) {
            try {
                const float a = std::stof(n.attributes.at(attribute));
                element->padding = {a,a};
            } catch (const std::exception& ex) {
                invalid_attribute(from, attribute, n.attributes.at(attribute), ex.what());
            }
        }
    }

    inline void add_attribute_spacing(const Node& n, const std::string& from, LinearLayout * element) {
        const std::string attribute = "spacing";
        if (n.attributes.contains(attribute)) {
            try {
                const float a = std::stof(n.attributes.at(attribute));
                element->spacing = a;
            } catch (const std::exception& ex) {
                invalid_attribute(from, attribute, n.attributes.at(attribute), ex.what());
            }
        }
    }


}

#endif //RENDER_ENGINE_ADD_ATTRIBUTE_H