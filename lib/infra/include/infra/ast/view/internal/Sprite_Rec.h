/***************************************************************
 * Project:       render-engine
 * File:          R.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-14
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
#ifndef RENDER_ENGINE_AST_REC_H
#define RENDER_ENGINE_AST_REC_H

#include "infra/ast/Node.h"

namespace infra::ast {
    /**
     * @brief Represents a sprite rectangle configuration.
     *
     * Inherits from Node and defines base and incremental
     * values for selecting frames or sub-rectangles in a sprite sheet.
     */
    struct Sprite_Rec : Node {
        int base = 0; ///< Base value for sprite rectangle
        int increase = 0; ///< Increment applied
    };
}

#endif //RENDER_ENGINE_AST_REC_H