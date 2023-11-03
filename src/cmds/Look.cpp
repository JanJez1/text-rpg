#include "Look.h"

std::string Look::action(std::vector<std::string> params, Player& player) {
    auto current_room = player.get_current_room();

    if (params.size() == 0)
        return current_room->get_full_desc();
    std::string target_string = "";
    if (params.size() == 1) {
        if(params.at(0) == "at") {
            return "What do you want to look at?";
        }
        target_string = params.at(0);
    }
    else {
        if(params.at(0) != "at")
            return "Try 'look at' something.";
        if (params.size() == 2)
            target_string = params.at(1);
        else {
            return "You can look at one thing a time only.";
        }
    }

    // CREATURE IN ROOM
    auto creature = current_room->find_creature(target_string);
    if (creature)
        return creature->get_desc() + creature->get_status();

    // ITEM IN INVENTORY
    auto& inv = player.get_inv();
    auto iter = find_elem(params.at(0), inv);
    if(iter != inv.end()) {
        return (*iter)->get_desc();
    }

    // ITEM IN ROOM
    auto item = current_room->find_item(target_string);
    if(item) {
        return item->get_desc() + item->event_look();
    }

    // DETAILED DESCRIPTION IN ROOM
    auto detail_desc = current_room->find_detail(target_string);
    if (detail_desc != "")
        return detail_desc;
    
    return "You don't see " + target_string + " here.";
}
