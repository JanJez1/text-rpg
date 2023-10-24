#include "Drink.h"

std::string Drink::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to drink?";

    auto item = player.find_item(params.at(0));
    if(!item) 
        return "You don't have it.";
    if( item->get_object_type() != Object_Type::potion )
        return "You can't drink " + item->get_title() + ".";
    return player.event_heal();
}