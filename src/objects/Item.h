#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
    std::string m_key_name; // like 'sword', 'helmet' - MANDATORY
    std::string m_title; // like 'a silver sword', 'an ornated helmet'
    std::string m_desc; // like 'This is about three feet long sword made of silver.'
public:
    Item(std::string, std::string title = "unknown", std::string desc = "not described");
    std::string get_key_name() {return m_key_name;}
    std::string get_title() {return m_title;}
    std::string get_desc() {return m_desc;}
};

#endif // ITEM_H