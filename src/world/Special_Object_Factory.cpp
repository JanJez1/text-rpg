#include "../world_helper/Special_Object_Factory.h"

using namespace std;

unique_ptr<Item> Special_Object_Factory::create(string str, Room* room1, Room* room2, string target_item) {
    
    if (str == "bush1")
        return make_unique<Hidden_Exit>(
            "bush",
            "The bush is dense, covering the hidden exit.",
            room1,
            room2
        );

    return make_unique<Item>("blob", "", "useless piece of blob");
}


