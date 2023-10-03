#include "Remove.h"

std::string Remove::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to remove?";
    auto& inv = player.get_inv();
    auto iter = find_elem(params.at(0), inv);
    if(iter == inv.end()) 
        return "You don't have it.";

    if(!(*iter)->is_equipped())
        return "You don't have it worn.";
    return player.event_remove_item(iter);
}