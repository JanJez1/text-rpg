#include "Unlock.h"

using namespace std;

string Unlock::action(std::vector<std::string> params, Player& player) {
    if (params.size() != 1)
        return "What do you want to get?";

    auto current_room = player.get_current_room();
    string target_string = params.at(0);

    // CREATURE
    auto creature = current_room->find_creature(target_string);
    if(creature) {
        return "You can't unlock " + target_string + ".";
    }

    // DETAILED DESCRIPTION IN ROOM
    auto detail_desc = current_room->find_detail(target_string);
    if (detail_desc != "")
        return "You can't unlock " + target_string + ".";

    // ITEM
    auto& items = current_room->get_items();
    auto iter = find_elem(target_string, items);
    if(iter != items.end()) {        
        if((*iter)->get_object_state() == Object_State::opened) {
            return "The " + target_string + " is opened.";
        }
        if((*iter)->get_object_state() != Object_State::locked) {
            return "You can't unlock " + target_string + "."; 
        }
        
        // let's check if I have right key
        string name_of_key = (*iter)->get_action_item();
        auto &inv = player.get_inv();
        auto key_iter = find_if(inv.begin(), inv.end(),
            [&](unique_ptr<Item> & obj){ return obj->get_title() == name_of_key;});
        if(key_iter == inv.end()) 
            return "You don't have the right key.";
        inv.erase(key_iter); // all keys are for single use
        return (*iter)->event_unlock();
    }

    return "There is no " + target_string + " around.";
}
