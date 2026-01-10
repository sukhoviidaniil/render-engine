/***************************************************************
 * Project:       render-engine
 * File:          render-engine.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-16
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
#ifndef RENDER_ENGINE_AST_RENDER_ENGINE_H
#define RENDER_ENGINE_AST_RENDER_ENGINE_H
#include "Entity_Node.h"


namespace infra::ast {
    /**
     * @brief Represents render-engine's spawn point in the model AST.
     *
     * Inherits from Entity_Node and includes movement speed.
     */
    struct render-engineSpawn : Entity_Node {
        float speed = 1.0; ///< Movement speed of render-engine
    };
}

#endif //RENDER_ENGINE_AST_RENDER_ENGINE_H
