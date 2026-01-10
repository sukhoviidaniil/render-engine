/***************************************************************
 * Project:       render-engine
 * File:          CoinSpawn.h
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
#ifndef RENDER_ENGINE_AST_COINSPAWN_H
#define RENDER_ENGINE_AST_COINSPAWN_H
#include "Entity_Node.h"

namespace infra::ast {
    /**
     * @brief Represents a coin spawn entity in the model AST.
     *
     * Inherits from Entity_Node and adds a hitbox size property.
     */
    struct CoinSpawn : Entity_Node {
        float hitbox_size; ///< Size of the coin's collision hitbox
    };
}

#endif //RENDER_ENGINE_AST_COINSPAWN_H