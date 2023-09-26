#include "Drop.h"

std::string Drop::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to drop?";
    auto p_item = player.move_item_from_inv(params.at(0));
    if(p_item != nullptr) {
        std::string response = "You've dropped " + p_item->get_title() + "."; 
        player.get_current_room()->add_item(move(p_item));
        return response;
    }
    return "You don't see any " + params.at(0) + " here.";
}
