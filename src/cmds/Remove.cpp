#include "Remove.h"

std::string Remove::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to remove?";
    
    auto item = player.find_item(params.at(0));
    if(!item) 
        return "You don't have it.";

    if(!item->is_equipped())
        return "You don't have it worn.";
    return player.event_remove_item(item);
}