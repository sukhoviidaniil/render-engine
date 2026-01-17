/***************************************************************
 * Project:       Render_Engine
 * File:          Parser.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-12
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of Render_Engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/
#ifndef RENDER_ENGINE_PARSER_H
#define RENDER_ENGINE_PARSER_H

#include "Node.h"
#include "Token.h"

namespace rb::ui {
    class Parser {
    public:
        static std::unique_ptr<Node> parse(std::vector<Token> tokens);
    };
}

#endif //RENDER_ENGINE_PARSER_H