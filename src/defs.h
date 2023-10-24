#ifndef DEFS_H
#define DEFS_H

enum class Object_Type {
    creature,
    item,
    helmet, armour, boots, gauntlets,
    weapon, shield,
    potion,
    special,
    undefined
};

enum class Param_Type {
    str, dex, con,
    ac, attack,
    min_damage, max_damage,
    max_hp
};

enum class Object_State {
    unused,
    locked,
    opened,
    activated
};


#endif // DEFS_H