#include "Menu_Cmds.h"

std::string Menu_Help::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No parameters allowed.";
    return Main_Menu::get_config_help();
}

std::string Menu_Profile::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No parameters allowed.";
    std::string response = player.get_abilities_profile();
    response += "Ability points: " + std::to_string(player.get_base_param(Param_Type::free_ability_points))+ "\n";
    return response;
}

std::string Menu_Reset::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No parameters allowed.";
    Player_Factory player_factory;
    player = player_factory.create_default_player();
    player.set_state(Player_State::generate);
    return "Abilities set to default values.";
}

std::string Menu_Quit::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No parameters allowed.";
    player.set_state(Player_State::in_menu);
    return "";
}

std::string Menu_Play::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No parameters allowed.";
    Player_Factory player_factory;
    player_factory.raise_max_hp_per_con(player);
    player.set_state(Player_State::playing);
    return "";
}


