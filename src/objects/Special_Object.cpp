#include "Special_Object.h"

using namespace std;

Special_Object::Special_Object(string name, string desc, Room* current_room_)
    : Item{name, "", desc, Object_Type::special},
    object_state{Object_State::unused},
    current_room{current_room_}
{}