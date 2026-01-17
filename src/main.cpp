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


#include <filesystem>
#include <iostream>
#include <string>

#include "infra/ast/Node.h"
#include "rb/reference_serialization.h"
#include "rb/layout_engine/Parser.h"
#include "rb/layout_engine/Tokenizer.h"
#include "rb/layout_engine/UIFactory.h"
#include "rb/registry/AssetImporter.h"


int main() {

    const std::string data_path = "../data/";
    rb::rgst::AssetImporter::instance().load_from_file(data_path + "/bin/registry.rgst.json");

    const std::string serialized_scenes_dir = data_path + "bin/scenes/";
    const std::string ui_file = serialized_scenes_dir + "ui1.ui.xml";

    // Read and tokenize data
    std::vector<rb::ui::Token> tokens = rb::ui::Tokenizer::tokenize(ui_file);

    // Go through the tokens and create an AST UI nodes
    auto node_root = rb::ui::Parser::parse(tokens);

    // Create real UI elements from AST nodes
    std::unique_ptr<rb::ui::UIElement> root = rb::ui::UIFactory::instance().build(*node_root);


    return 0;
}
