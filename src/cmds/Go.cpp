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
    player.set_current_room(target_room);
            // can't use param, as it can be single char like 'n'
    return "You moved to the " + exit_to_string(exit) + "\n" + target_room->get_full_desc();
    
}
