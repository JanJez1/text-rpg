#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "../defs.h"
#include "../Object.h"

class Item: public Object
{
public:
    Item(std::string,
        std::string title = "unknown",
        std::string desc = "not described",
        Object_Type object_type = Object_Type::item);
};

#endif // ITEM_H