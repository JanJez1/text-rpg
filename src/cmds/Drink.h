#ifndef DRINK_H
#define DRINK_H

#include "Cmd_Base.h"
#include "../utils.h"
#include "../Object.h"
#include "../objects/Item.h"


class Drink : public Cmd_Base
{
public:
    virtual ~Drink() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // DRINK_H
