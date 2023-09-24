#include "World.h"

using namespace std;

void World::create_room(string key, string title, string desc) {
    // add check for duplicate id
    auto p_room = make_unique<Room>(title, desc);
    rooms.insert({key, move(p_room)});
    return;
}

void World::set_start_room(Room* p_room) {
    start_room = p_room;
    current_room = p_room;
}

void World::set_current_room(Room* p_room) {
    current_room = p_room;
}

Room* World::get_current_room() {
    if (current_room == nullptr) {
        return start_room;
    }
    return current_room;
}

void World::link_rooms(std::string room1 , Exit exit, std::string room2) {
    rooms[room1]->add_exit(exit, rooms[room2].get());
    rooms[room2]->add_exit(get_opposite_exit(exit), rooms[room1].get());
}


World::World()
: rooms{}, current_room{nullptr}
{
    create_room(
        "sq",
        "main square",
        "a quite large square covered with cobblestones. Currently only one street leads to the south."
    );
  
    create_room(
        "da1",
        "a dark ale",
        "This is a narrow dark street running among tiny houses. "
        "It opens to a square to the north while getting even darker to the south."
    );

    create_room(
        "da2",
        "a dark ale bending",
        "This is a narrow street running among tiny houses. It turns here abruptly."
    );

    create_room(
        "da3",
        "a dark ale dead end",
        "The dark ale ends here. The only exit is to the west."
    );
    
    set_start_room(rooms["sq"].get());
    
    link_rooms("sq", south, "da1");
    link_rooms("da1", south, "da2");
    link_rooms("da2", east, "da3");

    rooms["sq"]->add_item(make_unique<Item>(
        "knife",
        "an old rusty knife",
        "This knife is about ten inches long. It has rusty blade and batterend handle."
    ));

    
}


