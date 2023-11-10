#ifndef DEFS_H
#define DEFS_H

#include<map>

enum class Object_Type {
    creature,
    item,
    helmet, armour, boots, gauntlets,
    weapon, shield,
    potion,
    special,
    door,
    undefined
};

enum class Param_Type {
    str, dex, con,
    free_ability_points,
    ac, attack,
    min_damage, max_damage,
    max_hp,
    exp_rating,
    invalid
};

enum class Object_State {
    unused,
    locked,
    opened,
    activated
};

enum class Player_State {
    quit,
    config,
    generate,
    auto_generate,
    in_menu,
    playing,
    dead
};

enum class Menu_Item {
    in_menu,
    player_config_manual,
    player_config_auto,
    shutdown
};

#endif // DEFS_H