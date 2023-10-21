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
public:
    Special_Object(std::string name, std::string title, std::string desc, Room* current_room_);
    virtual ~Special_Object() = default;

    // GAME MECHANICS
    void set_object_state(Object_State state) override { object_state = state; };
    Object_State get_object_state() override { return object_state; }
    bool is_visible() override { return false; }
    bool is_pickable() override { return false; }
    // std::string event_look() override { return "";}
    // std::string event_unlock() override { return "";}
};

#endif // SPECIAL_OBJECT_H