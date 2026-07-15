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

#include "sif/event/Event_Bus.h"
#include "sif/layout_engine/UIFactory.h"

#include "App.h"
#include "sif/asset/internal/AssetImporter.h"


int main() {
    // File/folder constants
    const std::string data_path = "../data/";
    const std::string serialized_scenes_dir = data_path + "bin/scenes/";
    const std::string ui_file = serialized_scenes_dir + "ui1.ui.xml";

    // Instantiation of basic things

    sif::asset::AssetImporter::instance();
    const auto eventbus = std::make_shared<event::Event_Bus>(); // GLOBAL

    // Load and save the Registry of assets
    sif::asset::AssetImporter::instance().load_from_file(data_path + "/bin/registry.rgst.json");
    sif::asset::AssetImporter::instance().load_in_registry();
    sif::asset::AssetRegistry::instance().set_asset_dir(data_path + "graphics/");

    sif::ast::RB_Config rb_config {
        .type = sif::ast::RB_Type::SFML,
        .window_name = "Some name",
        .window_width = 800,
        .window_height = 600,
        .fps = 30
    };
    event::Event_Collector e;

    auto a = core::App(eventbus, rb_config, e, ui_file);
    a.run();

    return 0;
}
