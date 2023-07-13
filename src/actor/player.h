﻿#pragma once
#include "setting/data/menu_data.h"
#include "setting/data/player_data.h"

namespace actor {
    class actor_player_data {
    public:
        std::string icon;
        std::string key;
        std::string value;
        setting_data::menu_data::stats_column_type column;
        setting_data::menu_data::stats_inventory_column_type inventory_column;

        void log(setting_data::menu_data::menu_type a_menu);
    };

    class player {
    public:
        static std::vector<actor_player_data*> get_player_data(RE::PlayerCharacter*& a_player,
            setting_data::menu_data::menu_type a_menu);

    private:
        static void process_result_handling(setting_data::player_data*& a_player_data_element, float& a_current_result);
        static std::string process_max_handling(setting_data::player_data*& a_player_data_element,
            float& a_current_result);
        static void process_damage_resist(RE::PlayerCharacter*& a_player,
            setting_data::player_data*& a_player_data_element,
            actor_player_data*& a_player_data);
    };
}  // actor