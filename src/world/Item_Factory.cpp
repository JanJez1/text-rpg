#include "../world_helper/Item_Factory.h"

using namespace std;

unique_ptr<Item> Item_Factory::create(string str) {
    
    if (str == "key")
        return make_unique<Item>(
            "key",
            "a silver key",
            "This is a tiny key made of silver. It looks to be used very often."
        );

//    *****    PREDEFINED PARAMS FOR ARMOURS    ***********
    std::map<Param_Type, short> ac1 {
        {Param_Type::ac, 1}
    };
    std::map<Param_Type, short> ac2 {
        {Param_Type::ac, 2}
    };
    std::map<Param_Type, short> ac3 {
        {Param_Type::ac, 3}
    };

//    *****    ARMOURS    ***********
    if (str == "leather_helmet") {
        return make_unique<Item>(
            "helmet",
            "a leather helmet",
            "This is a simple helmet made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            ac1
        );
    }

    if (str == "leather_cap") {
        return make_unique<Item>(
            "cap",
            "a leather cap",
            "This is a simple cap made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            ac1
        );
    }

    if (str == "leather_boots_dex") {
        return make_unique<Item>(
            "boots",
            "leather boots of dexterity",
            "Light boots made of soft leather.",
            Object_Type::boots,
            std::map<Param_Type, short> {
              {Param_Type::ac, 1},
              {Param_Type::dex, 2}
            }
        );
    }

//    *****    SHIELDS    ***********
    if (str == "buckler") {
        return make_unique<Item>(
            "buckler",
            "a tiny buckler",
            "A tiny round shield measuring around one foot in diamater.",
            Object_Type::shield,
            ac1
        );
    }

    if (str == "heater_shield") {
        return make_unique<Item>(
            "shield",
            "a heater shield",
            "The shield made of thin wood overlaid with leather and braced with iron.",
            Object_Type::shield,
            ac2
        );
    }

//    *****    WEAPONS    ***********
    if (str == "stick") {
        return make_unique<Item>(
            "stick",
            "a wooden stick",
            "This is about one foot long and relatively strong piece of wood.",
            Object_Type::weapon,
            std::map<Param_Type, short> {
                {Param_Type::min_damage, 1},
                {Param_Type::max_damage, 2}
            }
        );
    }

    if (str == "rusty_dagger") {
        return make_unique<Item>(
            "dagger",
            "a rusty dagger",
            "An old rusty dagger. It is about a half foot long.",
            Object_Type::weapon,
            std::map<Param_Type, short> {
                {Param_Type::min_damage, 2},
                {Param_Type::max_damage, 4}
            }
        );
    }

    return make_unique<Item>("blob", "an unidentified blob", "useless piece of blob");
}


