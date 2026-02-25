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