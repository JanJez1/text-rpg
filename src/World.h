#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <memory>
#include "Room.h"
#include "Item.h"
#include "utils.h"

class World
{
private:
    std::map<std::string, std::unique_ptr<Room>> rooms;
    Room* current_room;
    Room* start_room;
   
    void create_room(std::string, std::string title="void", std::string desc="");
    void link_rooms(std::string, Exit, std::string);
public:
    World();

    void set_current_room(Room* p = nullptr);
    void set_start_room(Room* p = nullptr);
    Room* get_current_room();
};

#endif // WORLD_H
