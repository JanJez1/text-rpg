#include "Bush.h"

using namespace std;

Bush::Bush(Room* current_room_, Room* target_room_)
    : Special_Item{
        "bush",
        "The bush is dense, covering hidden exit."},
    current_room{current_room_},
    target_room{target_room_}
 {}

 std::string Bush::event_look() {
    if (get_item_state() == Item_State::activated)
        return "";
    set_item_state(Item_State::activated);
    current_room->add_exit(Exit::north, target_room);
    return "\nYou've discovered hidden exit behind the bush!";
 }