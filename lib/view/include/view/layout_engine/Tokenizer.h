/***************************************************************
 * Project:       Render_Engine
 * File:          Tokenizer.h
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
#ifndef RENDER_ENGINE_TOKENIZER_H
#define RENDER_ENGINE_TOKENIZER_H
#include <vector>

#include "Token.h"

namespace view::ui {
    class Tokenizer {
    public:
        explicit Tokenizer(std::string_view src);
        std::vector<Token> tokenize();
    private:
        std::string_view src_;
    };
}

#endif //RENDER_ENGINE_TOKENIZER_H