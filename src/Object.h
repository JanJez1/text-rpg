#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "defs.h"

class Object
{
private:
    std::string m_key_name; // like 'orc', 'sword' 
                            // - name under which can be targeted by player aka 'get sword'
    std::string m_title;    // like 'a silver sword', 'an orc warrior', 'an ornated helmet' 
                            // - this is shown in the room description when lying on the ground, or items in inventory
                            // - needs to be unique, serves also as an ID
    std::string m_desc;     // like 'This is about three feet long sword made of silver.'
    Object_Type m_object_type; // creature, sword, helmet, ...
public:
    Object(std::string, 
        std::string title = "unknown",
        std::string desc = "not described",
        Object_Type object_type = Object_Type::undefined
        );
    virtual ~Object() = default;

    std::string get_key_name() {return m_key_name;}
    std::string get_title() {return m_title;}
    virtual std::string get_desc() {return m_desc;}
    Object_Type get_object_type() { return m_object_type; }
    void set_object_type(Object_Type type) {  m_object_type = type; }
};

#endif // OBJECT_H