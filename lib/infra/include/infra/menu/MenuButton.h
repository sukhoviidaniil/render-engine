/***************************************************************
 * Project:       render-engine
 * File:          MenuButton.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-25
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of render-engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_MENUBUTTON_H
#define RENDER_ENGINE_MENUBUTTON_H
#include <memory>
#include <string>

#include "infra/event/Event.h"

namespace infra::menu {
    /**
     * @brief Represents a button in a menu.
     *
     * Associates a display name with an event that is triggered
     * when the button is activated.
     */
    struct MenuButton {
        std::string name; ///< Button display name
        /**
         * @brief Event triggered when the button is clicked.
         *
         * Stored as a type-erased event instance.
         *
         */
        std::unique_ptr<infra::event::EventConcept> event;
    };
}

#endif //RENDER_ENGINE_MENUBUTTON_H