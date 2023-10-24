#include "Room_Factory.h"

    Room* Room_Factory::create_room(std::string title, std::string desc, bool resetable) {
        auto unique_ptr_room = std::make_unique<Room>(title, desc, resetable);
        auto p_room = unique_ptr_room.get();
        rooms.push_back(std::move(unique_ptr_room));
        return p_room;
    }

    void Room_Factory::connect_rooms(Room *room1 , Exit exit, Room *room2, std::string door_str) {
        room1->add_exit(exit, room2);
        room2->add_exit(get_opposite_exit(exit), room1);
        if (door_str != "") {
            auto door = Special_Object_Factory::create(door_str);
            auto door2 = door;
            room1->add_door(exit, door);
            room2->add_door(get_opposite_exit(exit), door2);
        }
    }

