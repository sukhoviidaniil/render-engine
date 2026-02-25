/***************************************************************
 * Project:       Render_Engine
 * File:          Node.h
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
#ifndef RENDER_ENGINE_VIEW_AST_NODE_H
#define RENDER_ENGINE_VIEW_AST_NODE_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace sif::ui {
    struct Node {
        std::string tag;

        std::unordered_map<
            std::string,
            std::string
        > attributes;

        std::vector<
            std::unique_ptr<Node>
        > children;
    };
}

#endif //RENDER_ENGINE_VIEW_AST_NODE_H