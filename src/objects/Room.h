#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "../utils.h"
#include "Item.h"
#include "../world_helper/Item_Factory.h"
#include "Creature.h"
#include "../world_helper/Creature_Factory.h"

class Room
{

private:
    std::string m_title;
    std::string m_desc;
    std::map<Exit, Room*> m_exits;
    std::vector<std::unique_ptr<Item>> m_items;
    std::vector<std::unique_ptr<Creature>> m_creatures;
    bool resetable; // if room is resetable, it resets creatures from backup when entered
    std::vector<std::string> m_creatures_backup;
    time_t last_kill_time;
    
public:
    Room(std::string title = "void", std::string desc = "darkness", bool resetable_ = false);

    std::string get_full_desc();
    
    void add_exit(Exit, Room*);
    Room* get_exit(Exit);
    void event_enter();

    void add_item(std::string name);
    void add_item(std::unique_ptr<Item> item) { m_items.push_back(move(item)); }
    std::vector<std::unique_ptr<Item>>& get_items() {return m_items;}
    
    void add_creature(std::string name);
    std::vector<std::unique_ptr<Creature>>& get_creatures() {return m_creatures;}
    void creature_killed(Creature& killed);
};

#endif // ROOM_H
