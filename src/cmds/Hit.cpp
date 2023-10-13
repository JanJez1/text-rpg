#include "Hit.h"

std::string Hit::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";

    // CREATURE
    auto& creatures = player.get_current_room()->get_creatures();
    auto itr = find_elem(params.at(0), creatures);
    if(itr != creatures.end()) {
        Combat combat{};
        return combat.compute_round(player, *(*itr));
        //return (*iter2)->die();
    }

    // ITEM
    auto& items = player.get_current_room()->get_items();
    auto itr2 = find_elem(params.at(0), items);
    if(itr2 != items.end()) {
        return "You can't attack " + params.at(0) + ".";
    }

    return "There is no " + params.at(0) + " around.";
}
