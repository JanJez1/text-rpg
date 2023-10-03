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

    if (str == "leather_helmet")
        return make_unique<Armour>(
            "helmet",
            "a leather helmet",
            "This is a simple helmet made of hardened leather. It covers top of the head only.",
            1,
            Object_Type::helmet
        );

    if (str == "leather_cap")
        return make_unique<Armour>(
            "cap",
            "a leather cap",
            "This is a simple cap made of hardened leather. It covers top of the head only.",
            1,
            Object_Type::helmet
        );

    return make_unique<Item>("", "an unidentified blob");
}

