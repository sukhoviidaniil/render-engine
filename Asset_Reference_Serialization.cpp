/***************************************************************
 * Project:       Render_Engine
 * File:          Asset_Reference_Serialization.cpp
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-15
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

#include "rb/reference_serialization.h"
#include "rb/registry/AssetImporter.h"

int main() {
    infra::intr::Random::instance();
    infra::diag::Logger::instance();

    const std::string data_path = "../data/";
    rb::rgst::AssetImporter::instance().load_from_file(data_path + "/bin/registry.rgst.json");

    const std::string scenes_dir = data_path + "scenes/";
    const std::string serialized_scenes_dir = data_path + "bin/scenes/";

    rb::reference_serialization(scenes_dir, serialized_scenes_dir);

    return 0;
}