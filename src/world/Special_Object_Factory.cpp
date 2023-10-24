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

 
    if (str == "nest")
        return make_unique<Hidden_Item>(
            "nest",
            "This is a small bird nest, it seems to be abandoned for a long time.",
            current_room,
            "a tiny iron key"
        );

    if (str == "chest1")
        return make_unique<Chest>(
            "chest",
            "a chest", // chest is visible, we need the title here
            "A big old wooden chest with a tiny lock.",
            current_room,
            "a tiny iron key", // key
            "a heater shield"  // content
        );        

    return make_unique<Item>("blob", "", "useless piece of blob");
}

shared_ptr<Door> Special_Object_Factory::create(string str) {

    if (str == "gate1")
        return make_shared<Door>(
            "gate",
            "This is a massive iron gate.",
            "a massive iron key"
        );
        

    return make_shared<Door>("blob", "", "useless piece of blob");

}