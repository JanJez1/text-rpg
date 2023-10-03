#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "defs.h"

class Object
{
private:
    std::string m_key_name; // like 'orc', 'sword'
    std::string m_title; // like 'a silver sword', 'an orc warrior', 'an ornated helmet'
    std::string m_desc; // like 'This is about three feet long sword made of silver.'
    Object_Type m_object_type; // creature, sword, helmet, ...
public:
    Object(std::string, 
        std::string title = "unknown",
        std::string desc = "not described",
        Object_Type object_type = Object_Type::undefined
        );
    virtual ~Object() {};

    std::string get_key_name() {return m_key_name;}
    std::string get_title() {return m_title;}
    std::string get_desc() {return m_desc;}
    Object_Type get_object_type() { return m_object_type; }

    // overrides (perhaps would be enough to put it in Item.h
    virtual bool is_equipped() {return false;}
    virtual void set_equipped(bool) {}

    // other "Item" methods
    bool is_wearable();
    bool is_holdable();
};

#endif // OBJECT_H