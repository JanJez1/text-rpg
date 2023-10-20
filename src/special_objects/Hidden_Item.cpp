#include "Hidden_Item.h"

using namespace std;

Hidden_Item::Hidden_Item(string key_name, string desc, Room* current_room_, string target_item_)
    : Special_Object{key_name, desc, current_room_, nullptr, target_item_}
 {}

 std::string Hidden_Item::event_look() {
    if (get_object_state() == Object_State::activated)
        return "";
    set_object_state(Object_State::activated);
    current_room->add_item(target_item);
    return "\nYou've found " + target_item + "!";
 }