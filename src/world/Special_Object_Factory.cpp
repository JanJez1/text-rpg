#include "../world_helper/Special_Object_Factory.h"

using namespace std;

unique_ptr<Item> Special_Object_Factory::create(string str, Room* current_room, Room* target_room) {
    
    if (str == "bush1")
        return make_unique<Hidden_Exit>(
            "bush",
            "The bush is dense, covering the hidden exit.",
            current_room,
            target_room
        );

    return make_unique<Item>("blob", "", "useless piece of blob");
}

unique_ptr<Item> Special_Object_Factory::create(string str, Room* current_room, string target_item_name) {
    
    if (str == "nest")
        return make_unique<Hidden_Item>(
            "nest",
            "This is a small bird nest, it seems to be abandoned for a long time.",
            current_room,
            target_item_name
        );

    return make_unique<Item>("blob", "", "useless piece of blob");
}



