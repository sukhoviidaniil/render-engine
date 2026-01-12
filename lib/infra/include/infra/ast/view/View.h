/***************************************************************
 * Project:       render-engine
 * File:          View.h
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
#ifndef RENDER_ENGINE_AST_VIEW_H
#define RENDER_ENGINE_AST_VIEW_H


#include <vector>

#include "infra/ast/view/Font.h"
#include "infra/ast/view/Texture.h"
#include "infra/ast/view/sprites/Sprite.h"



namespace infra::ast {
    /**
     * @brief Represents the complete view configuration of the AST.
     *
     * Inherits from Node and contains window settings, resource paths,
     * and collections of textures, fonts, and sprites.
     */
    struct View : Node{
        std::string type = "None"; ///< Type identifier for the view
        unsigned int window_width = 0; ///< Width of the window
        unsigned int window_height = 0; ///< Height of the window
        int fps = 30; ///< Frames per second
        std::string view_directory; ///< Directory containing view assets

        std::vector<Texture> textures; ///< List of textures used
        std::vector<Font> fonts; ///< List of fonts used
        std::vector<Sprite> sprites; ///< List of simple sprites
    };
}

#endif //RENDER_ENGINE_AST_VIEW_H