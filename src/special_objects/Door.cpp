#include "Door.h"

using namespace std;

Door::Door(string name, string desc, string name_of_key_)
    : Special_Object{name, "", desc, nullptr},
      name_of_key{name_of_key_}
 {
    set_object_state(Object_State::locked);
    set_object_type(Object_Type::door);
 }

string Door::event_unlock() {
    set_object_state(Object_State::opened);
    return "\nYou've unlocked and opened the " + get_key_name() + "!";
 }

 string Door::get_desc() {
    string base_desc = Special_Object::get_desc();
    if (get_object_state() == Object_State::opened)
        return base_desc + " It is opened.";
    if (get_object_state() == Object_State::locked)
        return base_desc + " It is locked.";
    return base_desc;
 }