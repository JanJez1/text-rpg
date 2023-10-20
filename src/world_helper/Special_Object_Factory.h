#ifndef SPECIAL_OBJECT_FACTORY_H
#define SPECIAL_OBJECT_FACTORY_H

#include <string>
#include <memory>

#include "../objects/Item.h"
// #include "../objects/Room.h"
#include "../objects/Special_Object.h"
#include "../defs.h"
#include "../special_objects/Hidden_Exit.h"
#include "../special_objects/Hidden_Item.h"

class Room;

class Special_Object_Factory
{
public:
    static std::unique_ptr<Item> create(
        std::string special_item_name,
        Room* current_room,
        Room* target_room = nullptr
    );
};

#endif // SPECIAL_OBJECT_FACTORY_H