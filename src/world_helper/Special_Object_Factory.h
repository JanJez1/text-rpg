#ifndef SPECIAL_OBJECT_FACTORY_H
#define SPECIAL_OBJECT_FACTORY_H

#include <string>
#include <memory>

#include "../defs.h"
#include "../special_objects/Hidden_Exit.h"
#include "../special_objects/Hidden_Item.h"
#include "../special_objects/Chest.h"
#include "../special_objects/Door.h"

class Room;

class Special_Object_Factory
{
public:
    static std::unique_ptr<Special_Object> create(
    // static std::unique_ptr<Item> create(
        std::string special_item_name,
        Room* current_room,
        Room* target_room = nullptr
    );
    // for door we need shared ptr
    // static std::shared_ptr<Door> create( std::string special_item_name );
};

#endif // SPECIAL_OBJECT_FACTORY_H