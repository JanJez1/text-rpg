#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "utils.h"
#include "objects/Item.h"
#include "Creature.h"

class Room
{

private:
    std::string m_title;
    std::string m_desc;
    std::map<Exit, Room*> m_exits;
    std::vector<std::unique_ptr<Item>> m_items;
    std::vector<std::unique_ptr<Creature>> m_creatures;
    
public:
    Room(std::string title = "void", std::string desc = "darkness");

    std::string get_full_desc();
    
    void add_exit(Exit, Room*);
    Room* get_exit(Exit);

    void add_item(std::unique_ptr<Item> item) { m_items.push_back(move(item)); }
    std::vector<std::unique_ptr<Item>>& get_items() {return m_items;}
    
    void add_creature(std::unique_ptr<Creature> creature) { m_creatures.push_back(move(creature)); }
    std::vector<std::unique_ptr<Creature>>& get_creatures() {return m_creatures;}
};

#endif // ROOM_H
