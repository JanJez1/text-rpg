#include "Player_Factory.h"

using namespace std;


Player Player_Factory::create_default_player() {
     map<Param_Type, short> default_player_params {
        {Param_Type::str, 10},
        {Param_Type::dex, 10},
        {Param_Type::con, 10},
        {Param_Type::max_hp, 10},
        {Param_Type::ac, 8},
        {Param_Type::free_ability_points, 7}
     };
     return Player{default_player_params};
}

void Player_Factory::auto_generate_abilities(Player& player) {
    player.set_base_param(Param_Type::str, 18);
    player.set_base_param(Param_Type::dex, 12);
    player.set_base_param(Param_Type::con, 17);
}