#include "Chest.h"

using namespace std;

Chest::Chest(string name, string title, string desc, Room* current_room_, string name_of_key_)
    : Special_Object{name, title, desc, current_room_},
      name_of_key{name_of_key_},
      items{}
 {
    set_object_state(Object_State::locked);
 }

 string Chest::event_unlock() {
    set_object_state(Object_State::opened);
    if (items.size() >0 )
        for(const auto& item: items)
            current_room->add_item(item);
    return "\nYou've unlocked and opened the " + get_key_name() + "!";
 }

 string Chest::get_desc() {
    string base_desc = Special_Object::get_desc();
    if (get_object_state() == Object_State::opened)
        return base_desc + " It is opened.";
    if (get_object_state() == Object_State::locked)
        return base_desc + " It is locked.";
    return base_desc;
 }