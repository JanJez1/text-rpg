#ifndef SPECIAL_ITEM_H
#define SPECIAL_ITEM_H

#include <string>
#include <map>

#include "../defs.h"
#include "Item.h"

class Special_Item: public Item
{
private:
    Item_State item_state;
public:
    Special_Item(std::string key_name, std::string desc, Item_State item_state_ = Item_State::unused);
    virtual ~Special_Item() = default;

    // GAME MECHANICS
    void set_item_state(Item_State state) override { item_state = state; };
    Item_State get_item_state() override { return item_state; }
    // std::string event_look() override { return "";}
    // std::string event_unlock() override { return "";}
};

#endif // SPECIAL_ITEM_H