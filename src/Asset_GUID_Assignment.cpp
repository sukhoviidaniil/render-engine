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

#include "rb/registry/AssetImporter.h"

int main() {
    std::string path = "../data/";
    rb::rgst::AssetImporter::instance().load_from_path(path + "graphics/");
    rb::rgst::AssetImporter::instance().save_in_file(path + "/bin/registry.rgst.json");
    return 0;
}
