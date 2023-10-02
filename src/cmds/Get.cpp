#include "Get.h"

std::string Get::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";

    auto& items = player.get_current_room()->get_items();
    auto iter = find_elem(params.at(0), items);
    if(iter != items.end()) {
        return player.event_pick_item(iter);
    }
    return "You don't see any " + params.at(0) + " to be picked up.";
}
