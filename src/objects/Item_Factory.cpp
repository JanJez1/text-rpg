#include "Item_Factory.h"

using namespace std;

unique_ptr<Item> Item_Factory::create(string str) {
    
    if (str == "key")
        return make_unique<Item>(
            "key",
            "a silver key",
            "This is a tiny key made of silver. It looks to be used very often."
        );

//    *****    ARMOURS    ***********

    if (str == "leather_helmet") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 1}
        };
        return make_unique<Item>(
            "helmet",
            "a leather helmet",
            "This is a simple helmet made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            params
        );
    }

    if (str == "leather_cap") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 1}
        };
        return make_unique<Item>(
            "cap",
            "a leather cap",
            "This is a simple cap made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            params
        );
    }
    if (str == "leather_boots_dex") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 1},
            {Param_Type::dex, 2}
        };
        return make_unique<Item>(
            "boots",
            "leather boots of dexterity",
            "Light boots made of soft leather.",
            Object_Type::boots,
            params
        );
    }


//    *****    WEAPONS    ***********
    if (str == "stick") {
        std::map<Param_Type, short> params {
            {Param_Type::min_damage, 1},
            {Param_Type::max_damage, 2}
        };
        return make_unique<Item>(
            "stick",
            "a wooden stick",
            "This is about one foot long and relatively strong piece of wood.",
            Object_Type::weapon,
            params
        );
    }

    return make_unique<Item>("blob", "an unidentified blob", "useless piece of blob");
}


