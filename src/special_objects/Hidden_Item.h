#ifndef HIDDEN_ITEM_H
#define HIDDEN_ITEM_H

#include <string>

#include "../defs.h"
#include "../objects/Special_Object.h"
#include "../objects/Room.h"
// #include "../world_helper/Item_Factory.h"

class Hidden_Item: public Special_Object
{
public:
    Hidden_Item(std::string key_name, std::string desc, Room* current_room_, std::string target_item_);
    virtual ~Hidden_Item() = default;

    std::string event_look() override;
};

#endif // HIDDEN_ITEM_H