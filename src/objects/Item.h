#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "../Object.h"

class Item: public Object
{
private:
public:
    Item(std::string, std::string title = "unknown", std::string desc = "not described");
};

#endif // ITEM_H