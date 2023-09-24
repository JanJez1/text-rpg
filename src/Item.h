#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
private:
    std::string key_name; // like 'sword', 'helmet' - MANDATORY
    std::string title; // like 'a silver sword', 'an ornated helmet'
    std::string desc; // like 'This is about three feet long sword made of silver.'
public:
    Item(std::string, std::string title = "unknown", std::string desc = "not described");
    std::string get_key_name() {return key_name;}
    std::string get_title() {return title;}
    std::string get_desc() {return desc;}
};

#endif // ITEM_H