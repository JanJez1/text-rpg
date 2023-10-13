#ifndef WORLD_H
#define WORLD_H

#include <map>
#include <memory>
#include "objects/Room.h"
#include "objects/Item.h"
#include "world/Creature_Factory.h"
#include "world/Item_Factory.h"
#include "utils.h"

class World
{
private:
    std::map<std::string, std::unique_ptr<Room>> rooms;
    // Room* current_room;
    Room* start_room;
    Item_Factory item_factory;
    Creature_Factory creature_factory;
   
    void create_room(std::string, std::string title="void", std::string desc="");
    void link_rooms(std::string, Exit, std::string);
    void add_item(std::string room, std::string item);
    void add_creature(std::string room, std::string creature);

public:
    World();

    void set_start_room(Room* room) {start_room = room;}
    Room* get_start_room() {return start_room;}
};

#endif // WORLD_H
