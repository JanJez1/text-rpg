#ifndef SPECIAL_OBJECT_H
#define SPECIAL_OBJECT_H

#include <string>
#include <map>

#include "../defs.h"
#include "Item.h"

class Room;

class Special_Object: public Item
{
protected:
    Object_State object_state;
    Room* current_room;
    Room* target_room;
    std::string target_item;
public:
    Special_Object(std::string key_name, std::string desc, Room* current_room_, Room* target_room_, std::string target_item_);
    virtual ~Special_Object() = default;

    // GAME MECHANICS
    void set_object_state(Object_State state) override { object_state = state; };
    Object_State get_object_state() override { return object_state; }
    // std::string event_look() override { return "";}
    // std::string event_unlock() override { return "";}
};

#endif // SPECIAL_OBJECT_H