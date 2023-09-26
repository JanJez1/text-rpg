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
    auto p_item = player.get_current_room()->find_item(target_string);
    if(p_item != nullptr)
        return p_item->get_desc();
    p_item = player.find_item_in_inv(target_string);
    if(p_item != nullptr)
        return p_item->get_desc();
    return "You don't see " + target_string + " here.";
}
