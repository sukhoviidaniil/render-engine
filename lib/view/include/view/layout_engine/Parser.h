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

namespace view::ui {
    class Parser {
    public:
        explicit Parser(std::vector<Token> tokens);

        std::unique_ptr<Node> parse();

    private:
        std::vector<Token> tokens_;
    };
}

#endif //RENDER_ENGINE_PARSER_H