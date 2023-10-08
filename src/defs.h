#ifndef DEFS_H
#define DEFS_H

// #include <map>

enum class Object_Type {creature, item, helmet, armour, boots, gauntlets, weapon, shield, undefined};

enum class Param_Type {
    str, dex, con,
    ac, attack,
    min_damage, max_damage,
    max_hp
};

// map<Param_Type, short> default_creature_params = {
//     {Param_Type::str, 1},
//     {Param_Type::dex, 1},
//     {Param_Type::con, 1},
//     {Param_Type::ac,  5},
//     {Param_Type::attack, 1},
//     {Param_Type::min_damage, 1},
//     {Param_Type::max_damage, 2},
//     {Param_Type::max_hp, 1}
// };

#endif // DEFS_H