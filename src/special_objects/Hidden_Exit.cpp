#include "Hidden_Exit.h"

using namespace std;

Hidden_Exit::Hidden_Exit(string key_name, string desc, Room* room1, Room* room2)
    : Special_Object{key_name, desc, room1, room2}
 {}

 std::string Hidden_Exit::event_look() {
    if (get_object_state() == Object_State::activated)
        return "";
    set_object_state(Object_State::activated);
    room1->add_exit(Exit::north, room2);
    return "\nYou've found a hidden exit!";
 }