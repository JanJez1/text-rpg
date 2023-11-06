#include "Room_Factory.h"

    Room* Room_Factory::create_room(std::string title, std::string desc, bool resetable) {
        auto unique_ptr_room = std::make_unique<Room>(title, desc, resetable);
        auto p_room = unique_ptr_room.get();
        // rooms.push_back(std::move(unique_ptr_room));
        rooms.push_back(std::move(unique_ptr_room));
        return p_room;
    }

    void Room_Factory::connect_rooms(Room *room1 , Exit exit, Room *room2, std::string door_str) {
        room2->add_exit(get_opposite_exit(exit), room1);
        if (door_str != "") {
            auto object = Special_Object_Factory::create(door_str, room1, room2);
            if (object->get_object_type() == Object_Type::door) {
                std::shared_ptr<Special_Object> door1 = std::move(object);
                auto door2 = door1;
                room1->add_door(exit, door1);
                room2->add_door(get_opposite_exit(exit), door2);
            }
            else { // hidden_exit
                room1->add_special_item(move(object));
                return;
            }
        }
        room1->add_exit(exit, room2); // needs to be added for normal exit and door.
    }

