#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include <string>
#include <memory>

#include "Item.h"
#include "Armour.h"

class Item_Factory
{
public:
    std::unique_ptr<Item> create(std::string);
};

#endif // ITEM_FACTORY_H