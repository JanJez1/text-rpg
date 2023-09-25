#ifndef ARMOUR_H
#define ARMOUR_H

#include <string>

#include "Item.h"

class Armour: public Item
{
private:
    int m_ac; //ac = Armour Class
public:
    Armour(std::string, std::string title = "unknown", std::string desc = "not described", int ac = 0);
};

#endif // ARMOUR_H