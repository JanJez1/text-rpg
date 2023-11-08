#include "Player_Factory.h"

using namespace std;


Player Player_Factory::create_default_player() {
     return Player{get_default_params()};
}

void Player_Factory::auto_generate_abilities(Player& player) {
    int ability_points = player.get_base_param(Param_Type::free_ability_points);
    Param_Type abil_to_raise = Param_Type::invalid;
    for (int i{0}; i < ability_points; i++) {
        switch (random(3)) {
            case 1: abil_to_raise = Param_Type::str; break;
            case 2: abil_to_raise = Param_Type::dex; break;
            case 3: abil_to_raise = Param_Type::con; break;
            default: break;
        }
        if (abil_to_raise != Param_Type::invalid)
            player.raise_base_param(abil_to_raise, 1);
    }
    player.raise_base_param(Param_Type::free_ability_points, -ability_points);
    raise_max_hp_per_con(player);
    player.set_state(Player_State::playing);
}


void Player_Factory::raise_max_hp_per_con(Player& player) {
    int con_modif = player.get_ability_modifier(player.get_base_param(Param_Type::con));
    player.raise_base_param(Param_Type::max_hp, con_modif);
    player.event_heal();
}