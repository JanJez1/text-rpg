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

    std::vector<std::unique_ptr<Object>>::iterator iter;
    
    if (player.get_current_room() != nullptr) {
        auto& items = player.get_current_room()->get_items();
        iter = find_elem(target_string, items);
        if(iter != items.end()) {
            return (*iter)->get_desc();
        }
    }

    auto& inv = player.get_inv();
    iter = find_elem(target_string, inv);
    if(iter != inv.end()) {
        return (*iter)->get_desc();
    }

    return "You don't see " + target_string + " here.";
}
