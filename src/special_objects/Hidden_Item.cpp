#include "Hidden_Item.h"

using namespace std;

Hidden_Item::Hidden_Item(string name, string desc, Room* current_room_, string items_)
    : Special_Object{name, desc, current_room_},
      items{items_}   
{
}

 std::string Hidden_Item::event_look() {
    if (get_object_state() == Object_State::activated)
        return "";
    set_object_state(Object_State::activated);
    current_room->add_item(items);
    return "\nYou've found something!";
 }