#include "Get.h"

std::string Get::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";

    auto current_room = player.get_current_room();
    std::string target_string = params.at(0);

    // ITEM
    auto& items = current_room->get_items();
    auto iter = find_elem(target_string, items);
    if(iter != items.end()) {
        if ( (*iter)->get_object_type() == Object_Type::special)
            return "You can't pick up " + target_string + "."; 
        return player.event_pick_item(iter);
    }

    // CREATURE
    auto creature = current_room->find_creature(target_string);
    if(creature) {
        return "You can't pick up " + target_string + ".";
    }

    // DETAILED DESCRIPTION IN ROOM
    auto detail_desc = current_room->find_detail(target_string);
    if (detail_desc != "")
        return "You can't pick up " + target_string + ".";

    return "There is no " + target_string + " around.";
}
