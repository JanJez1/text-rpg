#ifndef DEFS_H
#define DEFS_H

#include<vector>

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
    ac, attack,
    min_damage, max_damage,
    max_hp,
    exp_rating
};

enum class Object_State {
    unused,
    locked,
    opened,
    activated
};

enum class Player_State {
    quit,
    generate,
    auto_generate,
    in_menu,
    playing,
    dead
};

enum class Menu_Item {
    in_menu,
    auto_generate,
    generate,
    quit
};

#endif // DEFS_H