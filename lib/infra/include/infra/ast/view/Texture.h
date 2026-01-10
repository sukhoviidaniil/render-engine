/***************************************************************
 * Project:       render-engine
 * File:          Texture.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2025-12-26
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
#ifndef RENDER_ENGINE_AST_TEXTURE_H
#define RENDER_ENGINE_AST_TEXTURE_H
#include <string>

#include "infra/ast/Node.h"

namespace infra::ast {
    /**
     * @brief Represents a texture resource in the AST.
     *
     * Inherits from Node and stores the texture's name and
     * the file path to its image resource.
     */
    struct Texture : Node{
        std::string name; ///< Name identifier for the texture
        std::string file; ///< File path to the texture image
    };
}

#endif //RENDER_ENGINE_AST_TEXTURE_H