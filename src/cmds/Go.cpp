#include "Go.h"


std::string Go::action(std::vector<std::string> params, Player& player) {
    if (params.size() == 0) 
        return "Where to go?";
    if(params.size() > 1)
        return "Too many exits.";
    Exit exit = string_to_exit(params.at(0));
    if(exit == invalid)
        return "Invalid exit.";
    Room* target_room = player.get_current_room()->get_exit(exit);
    if (target_room == nullptr)
        return "You can't go this way.";
    Special_Object* door = player.get_current_room()->get_door(exit);
    if (door != nullptr)
        if (door->get_object_state() == Object_State::locked)
            return "The way to the " + exit_to_string(exit) + " is blocked by the " + door->get_key_name() + ".";
    player.set_current_room(target_room);
    target_room->event_enter();
    return "You moved to the " + exit_to_string(exit) + "\n" + target_room->get_full_desc();
        // can't use param, as it can be single char like 'n'
}
