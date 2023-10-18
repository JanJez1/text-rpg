#include "Hit.h"

std::string Hit::action(std::vector<std::string> params, Player& player) {
    
    if (params.size() != 1)
        return "What do you want to get?";

    auto current_room = player.get_current_room();
    auto target_string = params.at(0);

    // CREATURE
    auto creature = current_room->find_creature(target_string);
    if(creature) {
        Combat combat{};
        return combat.compute_round(player, *creature);
    }

    // ITEM
    auto item = current_room->find_item(target_string);
    if(item) {
        return "You can't attack " + target_string + ".";
    }

    // ROOM DETAIL
    auto detail = current_room->find_detail(target_string);
    if(detail != "") {
        return "You can't attack " + target_string + ".";
    }

    return "There is no " + target_string + " around.";
}
