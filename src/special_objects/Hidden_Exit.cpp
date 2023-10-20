#include "Hidden_Exit.h"

using namespace std;

Hidden_Exit::Hidden_Exit(string name, string desc, Room* current_room_, Room* target_room_)
    : Special_Object{name, desc, current_room_},
      target_room{target_room_}
{}

 std::string Hidden_Exit::event_look() {
    if (get_object_state() == Object_State::activated)
        return "";
    set_object_state(Object_State::activated);
    current_room->add_exit(Exit::north, target_room);
    return "\nYou've found a hidden exit!";
 }