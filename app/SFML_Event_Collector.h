/***************************************************************
 * Project:       Render_Engine
 * File:          SFML_Event_Collector.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-19
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
#ifndef RENDER_ENGINE_SFML_EVENT_COLLECTOR_H
#define RENDER_ENGINE_SFML_EVENT_COLLECTOR_H

#include "infra/event/Event_Collector.h"
#include "SFML/Window/Event.hpp"
#include "my_sfml/ISFML_Event_Source.h"

namespace sif::sfml {
    class SFML_Event_Collector : public infra::event::Event_Collector {
    public:
        explicit SFML_Event_Collector(sif::sfml::ISFML_Event_Source& source);

        void collect() override;

    private:
        void dispatch(const sf::Event& e);

        sif::sfml::ISFML_Event_Source& source_;
    };
}

#endif //RENDER_ENGINE_SFML_EVENT_COLLECTOR_H
