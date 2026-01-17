/***************************************************************
 * Project:       Render_Engine
 * File:          reference_serialization.h
 *
 * Author:        Sukhovii Daniil
 * Created:       2026-01-17
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
#ifndef RENDER_ENGINE_REFERENCE_SERIALIZATION_H
#define RENDER_ENGINE_REFERENCE_SERIALIZATION_H
#include <filesystem>
#include <iostream>
#include <string>

#include "infra/diagnostics/Logger.h"
#include "layout_engine/Tokenizer.h"
#include "registry/AssetImporter.h"

namespace rb {
    inline void reference_serialization(const std::string& dir, const std::string& serialized_dir) {
        namespace fs = std::filesystem;
        for (auto &entry : fs::recursive_directory_iterator(dir)) {
            if (!entry.is_regular_file()) continue;

            const std::string &path = entry.path().string();

            if (!rb::ui::Tokenizer::is_ui_xml_file(path)) continue;
            try {
                std::vector<rb::ui::Token> tokens = rb::ui::Tokenizer::tokenize(path);

                fs::path relative_path = fs::relative(entry.path(), dir);

                fs::path target_path = fs::path(serialized_dir) / relative_path;

                fs::create_directories(target_path.parent_path());

                for (rb::ui::Token& token : tokens) {
                    auto it = token.attributes.find("asset_name");
                    if (it != token.attributes.end()) {
                        std::string asset_name = it->second;
                        asset::AssetDesc desc = rb::rgst::AssetImporter::instance().get(asset_name);
                        intrnl::GUID guid = desc.meta.guid;

                        token.attributes.erase(it);
                        token.attributes.emplace("guid", guid.string());
                    }
                }

                rb::ui::Tokenizer::save_tokens(target_path.string(), tokens);
            }catch (const std::exception &e) {
                std::string err =  "Reference Serialization - Failed to process file '" + path + "': " + e.what();
                LOG(err);
                std::cerr << err << "\n" << std::endl;
            }
        }
    }
}

#endif //RENDER_ENGINE_REFERENCE_SERIALIZATION_H