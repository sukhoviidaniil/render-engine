/***************************************************************
 * Project:       render-engine
 * File:          Grid.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-18
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
#ifndef RENDER_ENGINE_GRID_H
#define RENDER_ENGINE_GRID_H

#include "infra/ast/Node.h"
#include <vector>
#include <cstdint>

namespace infra::ast {

    /**
     * @brief Represents the type of a single tile in a game grid.
     */
    enum class Tile : std::uint8_t {
        Empty,
        Wall,
        CoinSpawn,
        PowerPelletSpawn,
        render-engineSpawn,
        GhostSpawn,
        Barrier
    };

    /**
     * @brief Represents a 2D grid of tiles for the game map.
     *
     * Inherits from Model_Node and contains dimensions, tile size,
     * and a 2D vector of tile values.
     */
    struct Grid : Model_Node {
        size_t rows; ///< Number of rows in the grid
        size_t columns; ///< Number of columns in the grid
        float tile_size; ///< Size of each tile
        std::vector<std::vector<Tile>> grid; ///< 2D array of tile values
    };
}
#endif //RENDER_ENGINE_GRID_H
