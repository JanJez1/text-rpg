#ifndef ROOM_FACTORY_H
#define ROOM_FACTORY_H

#include <string>
#include <memory>
#include <map>
#include <iostream>

#include "../objects/Room.h"
#include "../defs.h"
#include "../utils.h"
#include "Special_Object_Factory.h"

class Room_Factory
{
private:
    std::vector<std::unique_ptr<Room>> rooms;
    Room *start_room;

    Room* create_room(std::string title, std::string desc, bool resetable = false);
    void connect_rooms(Room *room1 , Exit exit, Room *room2, std::string door_str ="");

public:
    Room_Factory() :
        rooms{},
        start_room{nullptr}
    {};

    void generate_rooms();
    Room* get_start_room() { return start_room; }
};

#endif // ROOM_FACTORY_H

