#ifndef LOOK_H
#define LOOK_H

#include "Cmd_Base.h"
#include "../World.h"
#include "../objects/Item.h"


class Look : public Cmd_Base
{
public:
    virtual ~Look() {};
    virtual std::string action(std::vector<std::string>, World&) override;
};

#endif // LOOK_H
