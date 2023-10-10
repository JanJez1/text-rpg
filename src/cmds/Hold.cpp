#include "Hold.h"

std::string Hold::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to hold?";
    auto& inv = player.get_inv();
    auto iter = find_elem(params.at(0), inv);
    if(iter == inv.end()) 
        return "You don't have it.";

    if((*iter)->is_equipped())
        return "You've already held it.";
    else if(!(*iter)->is_holdable() )
        return "You can't hold " + (*iter)->get_title() + ".";
    return player.event_equip_item(iter);
}