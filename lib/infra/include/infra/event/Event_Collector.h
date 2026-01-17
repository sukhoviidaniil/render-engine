/***************************************************************
 * Project:       render-engine
 * File:          Event_Collector.h
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
 *   This file is part of render-engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_EVENT_COLLECTOR_H
#define RENDER_ENGINE_EVENT_COLLECTOR_H

#include "infra/event/Event_Store.h"

namespace infra::event {
    class Event_Collector {
    public:
        virtual ~Event_Collector() = default;

        virtual void collect() = 0;
        Event_Store event_store_;
    };
}

#endif //RENDER_ENGINE_EVENT_COLLECTOR_H