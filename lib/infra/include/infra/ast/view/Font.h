/***************************************************************
 * Project:       render-engine
 * File:          Font.h
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
#ifndef RENDER_ENGINE_AST_FONT_H
#define RENDER_ENGINE_AST_FONT_H
#include "ViewNode.h"

namespace infra::ast {

    /**
     * @brief Represents a font resource in the AST.
     *
     * Inherits from Node and stores the font's name and
     * the path to its file.
     */
    struct Font : Node{
        std::string font; ///< Name of the font
        std::string file; ///< File path to the font resource
    };
}

#endif //RENDER_ENGINE_AST_FONT_H