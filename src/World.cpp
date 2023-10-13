#include "World.h"

using namespace std;

void World::create_room(string key, string title, string desc) {
    // add check for duplicate id
    auto p_room = make_unique<Room>(title, desc);
    rooms.insert({key, move(p_room)});
    return;
}


void World::link_rooms(std::string room1 , Exit exit, std::string room2) {
    rooms[room1]->add_exit(exit, rooms[room2].get());
    rooms[room2]->add_exit(get_opposite_exit(exit), rooms[room1].get());
}

void World::add_item(std::string room, std::string item) {
    rooms[room]->add_item(item_factory.create(item));
}

void World::add_creature(std::string room, std::string creature) {
    rooms[room]->add_creature(creature_factory.create(creature));
}


World::World()
    : rooms{},
      start_room{nullptr},
      item_factory{},
      creature_factory{}
{
    create_room(
        "sq",
        "main square",
        "a quite large square covered with cobblestones. Currently only one narrow street leads to the south."
    );
    add_item("sq", "leather_helmet");
    add_item("sq", "leather_cap");
    add_item("sq", "key");
    add_item("sq", "leather_boots_dex");
    add_item("sq", "stick");
    add_item("sq", "rusty_dagger");
    add_item("sq", "heater_shield");
    add_item("sq", "buckler");
      
    create_room(
        "dl1",
        "a dark lane",
        "This is a narrow dark street running among tiny houses. "
        "It opens to a square to the north while getting even darker to the south."
    );
    add_creature("dl1", "green_orc");

    create_room(
        "dl2",
        "a dark lane bending",
        "This is a narrow street running among tiny houses. It turns here abruptly."
    );
    add_creature("dl2", "rat");

    create_room(
        "dl3",
        "a dark lane dead end",
        "The dark lane ends here. The only exit is to the west."
    );
    add_item("dl3", "leather_helmet");
    
    set_start_room(rooms["sq"].get());
    
    link_rooms("sq", south, "dl1");
    link_rooms("dl1", south, "dl2");
    link_rooms("dl2", east, "dl3");
}


