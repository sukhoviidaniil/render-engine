/***************************************************************
 * Project:       render-engine
 * File:          View.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-06
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


#include <utility>

#include "view/View.h"

namespace view {
    View::View(std::string name) : name_(std::move(name)) {
    }

    View::~View() = default;
}

