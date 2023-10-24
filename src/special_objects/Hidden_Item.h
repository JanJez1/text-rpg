#ifndef HIDDEN_ITEM_H
#define HIDDEN_ITEM_H

#include <string>

#include "../defs.h"
#include "../objects/Special_Object.h"
#include "../objects/Room.h"

class Hidden_Item: public Special_Object
{
private:
    std::string items;
public:
    Hidden_Item(std::string name, std::string desc, Room* current_room_, std::string target_item_);
    virtual ~Hidden_Item() = default;

    std::string event_look() override;
};

#endif // HIDDEN_ITEM_H