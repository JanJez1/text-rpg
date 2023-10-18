#ifndef ROOM_FACTORY_H
#define ROOM_FACTORY_H

#include <string>
#include <memory>
#include <map>
#include <iostream>

#include "../objects/Room.h"
#include "../defs.h"
#include "../utils.h"

class Room_Factory
{
private:
    std::map<std::string, std::unique_ptr<Room>> rooms;
    Room *start_room;
    
    Room* create_room(std::string room_id, std::string title, std::string desc, bool resetable = false) {
        auto unique_ptr_room = std::make_unique<Room>(title, desc, resetable);
        auto p_room = unique_ptr_room.get();
        rooms.insert({room_id, std::move(unique_ptr_room)});
        return p_room;
    }

    void connect_rooms(Room *room1 , Exit exit, Room *room2) {
        room1->add_exit(exit, room2);
        room2->add_exit(get_opposite_exit(exit), room1);
    }

public:
    Room_Factory() :
        rooms{},
        start_room{nullptr}
    {};

    void generate_rooms();
    Room* get_start_room() { return start_room; }
};

#endif // ROOM_FACTORY_H

