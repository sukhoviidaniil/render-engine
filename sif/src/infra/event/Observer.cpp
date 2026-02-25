/***************************************************************
 * Project:       Render_Engine
 * File:          Observer.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-02-01
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

#include "infra/event/Observer.h"

namespace sif::infra::event {
    Observer::Observer() = default;

    Observer::~Observer() {
        un_track_all();
    }

    void Observer::track(Event_Bus::Subscription s) {
        subs_.push_back(std::move(s));
    }

    void Observer::un_track_all() {
        for (auto& sub : subs_) {
            sub.unsubscribe();
        }
        subs_.clear();
    }
}
