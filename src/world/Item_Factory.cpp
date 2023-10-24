#include "../world_helper/Item_Factory.h"

using namespace std;

unique_ptr<Item> Item_Factory::create(string title) {
    
    if (title == "a tiny iron key")
        return make_unique<Item>(
            "key",
            title,
            "This is a tiny key made of iron. It is quite rusty."
        );
    if (title == "a massive iron key")
        return make_unique<Item>(
            "key",
            title,
            "This is a massive key made of iron. It is quite rusty."
        );

    if (title == "a healing potion") // universal healing potion, no variants available
        return make_unique<Item>(
            "potion",
            title,
            "A tiny flask filled with red liquid bearing the sign 'healing potion'.",
            Object_Type::potion
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
    if (title == "a leather helmet") {
        return make_unique<Equipment>(
            "helmet",
            title,
            "This is a simple helmet made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            ac1
        );
    }

    if (title == "a leather cap") {
        return make_unique<Equipment>(
            "cap",
            title,
            "This is a simple cap made of hardened leather. It covers top of the head only.",
            Object_Type::helmet,
            ac1
        );
    }

    if (title == "leather boots of dexterity") {
        return make_unique<Equipment>(
            "boots",
            title,
            "Light boots made of soft leather.",
            Object_Type::boots,
            std::map<Param_Type, short> {
              {Param_Type::ac, 1},
              {Param_Type::dex, 2}
            }
        );
    }

//    *****    SHIELDS    ***********
    if (title == "a tiny buckler") {
        return make_unique<Equipment>(
            "buckler",
            title,
            "A tiny round shield measuring around one foot in diamater.",
            Object_Type::shield,
            ac1
        );
    }

    if (title == "a heater shield") {
        return make_unique<Equipment>(
            "shield",
            title,
            "The shield made of thin wood overlaid with leather and braced with iron.",
            Object_Type::shield,
            ac2
        );
    }

//    *****    WEAPONS    ***********
    if (title == "a wooden stick") {
        return make_unique<Equipment>(
            "stick",
            title,
            "This is about one foot long and relatively strong piece of wood.",
            Object_Type::weapon,
            std::map<Param_Type, short> {
                {Param_Type::min_damage, 1},
                {Param_Type::max_damage, 2}
            }
        );
    }

    if (title == "a rusty dagger") {
        return make_unique<Equipment>(
            "dagger",
            title,
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


