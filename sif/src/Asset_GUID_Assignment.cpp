/***************************************************************
 * Project:       Render_Engine
 * File:          Asset_GUID_Assignment.cpp
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

#include <iostream>

#include "sif/infra/diagnostics/Logger.h"
#include "sif/asset/internal/AssetImporter.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0]
                  << " <graphics_dir> <registry_file>" << std::endl;
        return 1;
    }

    const std::string graphics_dir = argv[1];
    const std::string registry_file = argv[2];
    sif::asset::AssetImporter::instance().load_from_path(graphics_dir);
    sif::asset::AssetImporter::instance().save_in_file(registry_file);
    return 0;
}
