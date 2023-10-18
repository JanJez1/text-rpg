#include "Special_Item.h"

using namespace std;

Special_Item::Special_Item(string key_name, string desc, Item_State item_state_)
    : Item{key_name, "", desc, Object_Type::game_mechanics},
    item_state{item_state_}
 {}