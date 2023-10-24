#include "Drink.h"

std::string Drink::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to drink?";

    auto& inv = player.get_inv();
    auto iter = find_elem(params.at(0), inv);

    if(iter == inv.end())
        return "You don't have it.";

    if( (*iter)->get_object_type() != Object_Type::potion )
        return "You can't drink " + (*iter)->get_title() + ".";
    
    inv.erase(iter);
    return player.event_heal();
}