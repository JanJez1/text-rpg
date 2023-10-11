#include "Look.h"

std::string Look::action(std::vector<std::string> params, Player& player) {
    if (params.size() == 0)
        return player.get_current_room()->get_full_desc();
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

    // ITEMS IN ROOM
    auto& items = player.get_current_room()->get_items();
    std::vector<std::unique_ptr<Item>>::iterator itr_items;
    itr_items = find_elem(target_string, items);
    if(itr_items != items.end()) {
        return (*itr_items)->get_desc();
    }
    // CREATURES IN ROOM
    auto& creatures = player.get_current_room()->get_creatures();
    std::vector<std::unique_ptr<Creature>>::iterator itr_creatures;
    itr_creatures = find_elem(target_string, creatures);
    if(itr_creatures != creatures.end()) {
        return (*itr_creatures)->get_desc();
    }

    // ITEMS IN INVENTORY
    auto& inv = player.get_inv();
    itr_items = find_elem(target_string, inv);
    if(itr_items != inv.end()) {
        return (*itr_items)->get_desc();
    }

    return "You don't see " + target_string + " here.";
}
