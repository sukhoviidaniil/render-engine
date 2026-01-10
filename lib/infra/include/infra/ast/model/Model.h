/***************************************************************
 * Project:       render-engine
 * File:          Model.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-15
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
#ifndef RENDER_ENGINE_AST_MODEL_H
#define RENDER_ENGINE_AST_MODEL_H

#include "CoinSpawn.h"
#include "GhostSpawn.h"
#include "Grid.h"
#include "render-engineSpawn.h"
#include "PowerPelletSpawn.h"

namespace infra::ast {
    /**
     * @brief Represents the complete game model AST.
     *
     * Inherits from Model_Node and aggregates all main components:
     * grid layout, entity spawns for render-engine, ghosts, coins, and power pellets.
     */
    struct Model : Model_Node{
        Grid grid; ///< Game grid layout
        render-engineSpawn pacman_spawn; ///< Game grid layout
        GhostSpawn ghost_spawn; ///< Ghost starting positions
        CoinSpawn coin_spawn; ///< Coin spawn configuration
        PowerPelletSpawn power_pellet_spawn; ///< Power pellet spawn configuration
    };
}

#endif //RENDER_ENGINE_AST_MODEL_H