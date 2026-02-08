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

#include "layout_engine/Token.h"

namespace sif::ui {
    class Tokenizer {
    public:
        static bool is_ui_xml_file(const std::string& path);
        static std::vector<Token> tokenize(const std::string& path);
        static void save_tokens(const std::string& path, const std::vector<Token>& tokens);

    private:
        static void ensure_ui_xml_file(const std::string &path, bool must_exist = true);
    };
}

#endif //RENDER_ENGINE_TOKENIZER_H