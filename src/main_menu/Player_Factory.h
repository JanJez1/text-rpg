#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include <string>
#include <memory>

#include "../objects/Player.h"
#include "../defs.h"
#include "../utils.h"

class Player_Factory
{
public:
    Player create_default_player();
    void auto_generate_abilities(Player&);
    void raise_max_hp_per_con(Player&);

    auto get_default_params() {
        return std::map<Param_Type, short> {
            {Param_Type::str, 10},
            {Param_Type::dex, 10},
            {Param_Type::con, 10},
            {Param_Type::max_hp, 10},
            {Param_Type::ac, 8},
            {Param_Type::free_ability_points, 7}
        };
    };
};

#endif // PLAYER_FACTORY_H