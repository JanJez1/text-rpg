#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "../defs.h"
#include "../Object.h"

class Item: public Object
{
private:
    bool equipped;

public:
    Item(std::string,
        std::string title = "unknown",
        std::string desc = "not described",
        Object_Type object_type = Object_Type::item);
    
    bool is_equipped() { return equipped; }
    void set_equipped(bool eq) override { equipped = eq; }
};

#endif // ITEM_H