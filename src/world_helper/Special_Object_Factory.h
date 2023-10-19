#ifndef SPECIAL_OBJECT_FACTORY_H
#define SPECIAL_OBJECT_FACTORY_H

#include <string>
#include <memory>

#include "../objects/Item.h"
// #include "../objects/Room.h"
#include "../objects/Special_Object.h"
#include "../defs.h"
#include "../special_objects/Hidden_Exit.h"

class Room;

class Special_Object_Factory
{
public:
    static std::unique_ptr<Item> create(std::string, Room* room1 = nullptr, Room* room2 = nullptr, std::string target_item = "");
};

#endif // SPECIAL_OBJECT_FACTORY_H