#include "../world_helper/Special_Object_Factory.h"

using namespace std;

unique_ptr<Special_Object> Special_Object_Factory::create(string str, Room* current_room, Room* target_room) {
    
    if (str == "boat")
        return make_unique<Hidden_Item>(
            "boat",
            "This is abandoned wreckage of a small partially decked boat.",
            current_room,
            "a pair of shabby shoes"
        );

    if (str == "bush1")
        return make_unique<Hidden_Exit>(
            "bush",
            "The bush is dense, covering the hidden exit.",
            current_room,
            target_room
        );
    
    if (str == "gate1")
        return make_unique<Door>(
            "gate",
            "This is a massive iron gate with a huge keyhole.",
            "a massive iron key"
        );
 
    if (str == "nest")
        return make_unique<Hidden_Item>(
            "nest",
            "This is a small bird nest, it seems to be abandoned for a long time.",
            current_room,
            "a tiny iron key"
        );

    if (str == "chest1") {
        auto chest = make_unique<Chest>(
            "chest",
            "a chest",                          // chest is visible, we need the title here
            "A big old wooden chest with a tiny lock.",
            current_room,
            "a tiny iron key"                   //key to unlock
        );
        chest->add_item("a leather cap");       // content of the chest
        chest->add_item("a healing potion");    //
        return move(chest);
    }

    // for "error" object used chest - only visible Special_Object
    return make_unique<Chest>("error", "error",
        "'" + str + "' is not among available special objects. Typo, perhaps?", nullptr, "");
}