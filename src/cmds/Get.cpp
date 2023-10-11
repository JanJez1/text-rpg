#include "Get.h"

std::string Get::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";

    // ITEM
    auto& items = player.get_current_room()->get_items();
    auto iter = find_elem(params.at(0), items);
    if(iter != items.end()) {
        return player.event_pick_item(iter);
    }

    // CREATURE
    auto& creatures = player.get_current_room()->get_creatures();
    auto iter2 = find_elem(params.at(0), creatures);
    if(iter2 != creatures.end()) {
        return "You can't pick up " + params.at(0) + ".";
    }

    // return "You don't see any " + params.at(0) + " to be picked up.";
    return "There is no " + params.at(0) + " around.";
}
