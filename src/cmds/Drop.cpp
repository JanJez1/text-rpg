#include "Drop.h"

std::string Drop::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to drop?";
    auto& inv = player.get_inv();
    auto iter = find_elem(params.at(0), inv);
    if(iter != inv.end()) {
        return player.event_drop_item(iter);
    }
    return "You don't have it.";
}