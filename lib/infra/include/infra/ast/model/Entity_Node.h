/***************************************************************
 * Project:       render-engine
 * File:          Entity_Node.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-22
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
#ifndef RENDER_ENGINE_ENTITY_NODE_H
#define RENDER_ENGINE_ENTITY_NODE_H
#include "infra/ast/Node.h"

namespace infra::ast {
    /**
     * @brief Represents an entity in the model AST.
     *
     * Inherits from Model_Node and adds entity-specific properties.
     */
    struct Entity_Node : Model_Node {
        float sprite_size; ///< Size of the entity's sprite
    };
}

#endif //RENDER_ENGINE_ENTITY_NODE_H