#ifndef CHEST_H
#define CHEST_H

#include <string>

#include "../defs.h"
#include "../objects/Special_Object.h"
#include "../objects/Room.h"

class Chest: public Special_Object
{
private:
    std::string name_of_key;
    std::string items;
public:
    Chest(std::string name, std::string desc, Room* current_room_, std::string name_of_key, std::string items_);
    virtual ~Chest() = default;

    std::string event_unlock() override;
    std::string get_action_item() override { return name_of_key;}
    std::string get_desc() override;
};

#endif // CHEST_H