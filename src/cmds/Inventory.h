#ifndef INVENTORY_H
#define INVENTORY_H

#include "Cmd_Base.h"
// #include "../World.h"
#include "../objects/Item.h"


class Inventory : public Cmd_Base
{
public:
    virtual ~Inventory() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // INVENTORY_H
