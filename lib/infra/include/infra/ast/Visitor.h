/***************************************************************
 * Project:       render-engine
 * File:          Visitor.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-17
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
#ifndef RENDER_ENGINE_VISITOR_H
#define RENDER_ENGINE_VISITOR_H

namespace infra::ast {


    // ----------------------------
    // Basic Visitor Interfaces
    // ----------------------------

    /**
     * @brief Base visitor interface.
     *
     * Provides a virtual destructor for proper polymorphic cleanup.
     */
    struct Visitor {
        virtual ~Visitor() = default;
    };

}

#endif //RENDER_ENGINE_VISITOR_H