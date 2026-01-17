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

#include <string>


#include "infra/event/Event_Bus.h"
#include "rb/layout_engine/Parser.h"
#include "rb/layout_engine/Tokenizer.h"
#include "rb/layout_engine/UIFactory.h"
#include "rb/registry/AssetImporter.h"


int main() {
    // File/folder constants
    const std::string data_path = "../data/";
    const std::string serialized_scenes_dir = data_path + "bin/scenes/";
    const std::string ui_file = serialized_scenes_dir + "ui1.ui.xml";

    // Instantiation of basic things
    infra::intr::Random::instance();
    infra::diag::Logger::instance();
    rb::rgst::AssetImporter::instance();
    const auto eventbus_ = std::make_shared<infra::event::Event_Bus>(); // GLOBAL

    // Load and save the Registry of assets
    rb::rgst::AssetImporter::instance().load_from_file(data_path + "/bin/registry.rgst.json");
    rb::rgst::AssetImporter::instance().load_in_registry();



    return 0;
}
