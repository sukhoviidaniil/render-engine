/***************************************************************
 * Project:       Render_Engine
 * File:          Token.h
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
#ifndef RENDER_ENGINE_TOKEN_H
#define RENDER_ENGINE_TOKEN_H
#include <string>
#include <unordered_map>

namespace view::ui {
    enum class TokenType {
        OpenTag,
        CloseTag,
        SelfCloseTag,
        Text
    };

    struct Token {
        TokenType type;

        std::string name;

        std::unordered_map<
            std::string,
            std::string
        > attributes;
    };
}

#endif //RENDER_ENGINE_TOKEN_H