/***************************************************************
 * Project:       ui-layout-engine
 * File:          main.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-09
 * Modified:      []
 *
 * Description:   []
 *
 * Contact:
 *   Email:       sukhovii.daniil@gmail.com
 *
 * Disclaimer:
 *   This file is part of ui-layout-engine.
 *   Unauthorized use, reproduction, or distribution is prohibited.
***************************************************************/


#include <fstream>
#include <string>
#include <string_view>

#include "rb/layout_engine/Parser.h"
#include "rb/layout_engine/Tokenizer.h"

std::string load_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file");
    }

    file.seekg(0, std::ios::end);
    std::string data(file.tellg(), '\0');
    file.seekg(0);

    file.read(data.data(), data.size());
    return data;
}

int main() {
    std::string buffer = load_file("../ui.xml");
    const std::string_view view_string(buffer);

    std::vector<rb::ui::Token> tokens = rb::ui::Tokenizer::tokenize(view_string);

    auto root = rb::ui::Parser::parse(tokens);

    return 0;
}