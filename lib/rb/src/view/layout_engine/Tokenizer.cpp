/***************************************************************
 * Project:       Render_Engine
 * File:          Tokenizer.cpp
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

#include "rb/layout_engine/Tokenizer.h"

namespace rb::ui {


    static void skip_ws(const std::string_rb src, size_t& i) {
        while (i < src.size() && std::isspace(static_cast<unsigned char>(src[i]))) {
            ++i;
        }
    }

    std::vector<Token> Tokenizer::tokenize(const std::string_rb src) {
        std::vector<Token> tokens;
        size_t i = 0;

        while (i < src.size()) {
            // ---------- TEXT ----------
            if (src[i] != '<') {
                size_t start = i;
                while (i < src.size() && src[i] != '<') {
                    ++i;
                }

                std::string text(src.substr(start, i - start));
                if (!text.empty()) {
                    tokens.push_back(Token{
                        TokenType::Text,
                        std::move(text),
                        {}
                    });
                }
                continue;
            }

            // ---------- TAG ----------
            ++i; // skip '<'
            skip_ws(src, i);

            bool isClosing = false;
            if (i < src.size() && src[i] == '/') {
                isClosing = true;
                ++i;
                skip_ws(src, i);
            }

            // tag name
            size_t nameStart = i;
            while (i < src.size() &&
                   (std::isalnum(static_cast<unsigned char>(src[i])) || src[i] == '_')) {
                ++i;
            }

            std::string tagName(src.substr(nameStart, i - nameStart));

            Token token;
            token.name = std::move(tagName);

            // ---------- CLOSE TAG ----------
            if (isClosing) {
                // skip until '>'
                while (i < src.size() && src[i] != '>') {
                    ++i;
                }
                if (i < src.size()) ++i;

                token.type = TokenType::CloseTag;
                tokens.push_back(std::move(token));
                continue;
            }

            // ---------- ATTRIBUTES ----------
            while (i < src.size()) {
                skip_ws(src, i);

                if (src[i] == '/' || src[i] == '>') {
                    break;
                }

                // attribute name
                size_t attrNameStart = i;
                while (i < src.size() &&
                       (std::isalnum(static_cast<unsigned char>(src[i])) || src[i] == '_')) {
                    ++i;
                }

                std::string attrName(src.substr(attrNameStart, i - attrNameStart));
                skip_ws(src, i);

                if (i < src.size() && src[i] == '=') {
                    ++i;
                    skip_ws(src, i);
                }

                // attribute value
                std::string attrValue;
                if (i < src.size() && src[i] == '"') {
                    ++i;
                    size_t valueStart = i;
                    while (i < src.size() && src[i] != '"') {
                        ++i;
                    }
                    attrValue = std::string(src.substr(valueStart, i - valueStart));
                    if (i < src.size()) ++i;
                }

                token.attributes.emplace(
                    std::move(attrName),
                    std::move(attrValue)
                );
            }

            // ---------- TAG END ----------
            if (i < src.size() && src[i] == '/') {
                ++i; // skip '/'
                if (i < src.size() && src[i] == '>') ++i;
                token.type = TokenType::SelfCloseTag;
            } else {
                if (i < src.size() && src[i] == '>') ++i;
                token.type = TokenType::OpenTag;
            }

            tokens.push_back(std::move(token));
        }

        return tokens;
    }

}
