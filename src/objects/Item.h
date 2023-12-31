#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

#include "../defs.h"
#include "../Object.h"

class Item: public Object
{
private:
    std::map<Param_Type, short> item_params;
public:
    Item(std::string,
        std::string title,
        std::string desc,
        Object_Type object_type = Object_Type::item,
        std::map<Param_Type, short> item_params = std::map<Param_Type, short>{}
    );
    virtual ~Item() = default;

    const std::map<Param_Type, short>& get_item_params() { return item_params; }

    // TO OVERRIDE
    virtual bool is_equipped() { return false; }
    virtual void set_equipped(bool) {return;}
    virtual bool is_wearable() { return false; }
    virtual bool is_holdable() { return false; }
    virtual bool is_visible() { return true; } // visible in room description
    virtual bool is_pickable() { return true; }

    // SPECIAL ACTIONS - GAME MECHANICS - TO OVERRIDE
    virtual void set_object_state(Object_State) { };
    virtual Object_State get_object_state() { return Object_State::unused; }
    virtual std::string event_look() { return "";}
    virtual std::string event_unlock() { return "";}
    virtual std::string get_action_item() { return "";}
};

#endif // ITEM_H