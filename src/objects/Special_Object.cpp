#include "Special_Object.h"

using namespace std;

Special_Object::Special_Object(string key_name, string desc, Room* current_room_, Room* target_room_, string target_item)
    : Item{key_name, "", desc, Object_Type::special},
    object_state{Object_State::unused},
    current_room{current_room_},
    target_room{target_room_},
    target_item{target_item}
 {}