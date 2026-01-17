/***************************************************************
 * Project:       Render_Engine
 * File:          SFML_Font_AssetLoader.cpp
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

#include "my_sfml/SFML_Font_AssetLoader.h"

#include "my_sfml/SFMLFont.h"
#include "rb/asset/Font.h"
#include "rb/asset/data/AssetDataLoader.h"
#include "SFML/Graphics/Font.hpp"


namespace rb::sfml {
    void SFML_Font_AssetLoader::load_asset(asset::AssetRecord &record, const std::string& asset_dir) {
        std::unique_ptr<asset::data::FontNode> data = asset::data::AssetDataLoader::instance().load_Font_from_file(asset_dir + record.get_conf_path());
        sf::Font font;
        const std::string path = asset_dir + data->source;
        if (!font.loadFromFile(path)) {
            const std::string err = "Unable to load SFML font;\n";
            LOG(err);
            throw std::runtime_error(err);
        }
        SFMLFont ff;
        ff.font = std::move(font);

        const std::shared_ptr<asset::Font> fff = std::make_shared<asset::Font>(std::move(ff));

        record.set_data(fff);
        record.set_state(asset::AssetState::Ready);
    }
}
