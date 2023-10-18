#ifndef DEFS_H
#define DEFS_H

enum class Object_Type {creature, item, helmet, armour, boots, gauntlets, weapon, shield, game_mechanics, undefined};

enum class Param_Type {
    str, dex, con,
    ac, attack,
    min_damage, max_damage,
    max_hp
};

enum class Item_State {
    unused,
    locked,
    opened,
    activated
};

#endif // DEFS_H