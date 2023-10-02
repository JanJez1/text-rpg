#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "utils.h"
#include "objects/Item.h"
#include "Object.h"

class Room
{

private:
    std::string m_title;
    std::string m_desc;
    std::map<Exit, Room*> m_exits;
    std::vector<std::unique_ptr<Object>> m_items;
    
public:
    Room(std::string title = "void", std::string desc = "darkness");

    std::string get_full_desc();
    void add_exit(Exit, Room*);
    Room* get_exit(Exit);
    void add_item(std::unique_ptr<Object> item) { m_items.push_back(move(item)); }
    std::vector<std::unique_ptr<Object>>& get_items() {return m_items;}

};

#endif // ROOM_H
