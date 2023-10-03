#ifndef ARMOUR_H
#define ARMOUR_H

#include <string>

#include "Item.h"
#include "../defs.h"

class Armour: public Item
{
private:
    int m_ac; //ac = Armour Class
public:
    Armour(std::string,
        std::string title = "unknown",
        std::string desc = "not described",
        int ac = 0,
        Object_Type object_type = Object_Type::undefined);
    virtual ~Armour() = default;
};

#endif // ARMOUR_H