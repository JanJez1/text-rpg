#include "Get.h"

std::string Get::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";
    auto p_item = player.get_current_room()->move_item_from_room(params.at(0));
    if(p_item != nullptr) {
        std::string response = "You've picked up " + p_item->get_title() + "."; 
        player.add_item_to_inv(move(p_item));
        return response;
    }
    return "You don't see any " + params.at(0) + " here.";
}
