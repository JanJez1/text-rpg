#ifndef BUSH_H
#define BUSH_H

#include <string>

#include "../../defs.h"
#include "../../objects/Room.h"
#include "../../objects/Special_Item.h"

class Bush: public Special_Item
{
private:
    Room* current_room;
    Room* target_room;
public:
    Bush(Room* current_room_, Room* target_room_);
    virtual ~Bush() = default;

    std::string event_look() override;
};

#endif // BUSH_H