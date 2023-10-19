#include "Special_Object.h"

using namespace std;

Special_Object::Special_Object(string key_name, string desc, Room* room1_, Room* room2_)
    : Item{key_name, "", desc, Object_Type::special},
    object_state{Object_State::unused},
    room1{room1_},
    room2{room2_}
 {}