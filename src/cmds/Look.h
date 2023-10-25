#ifndef LOOK_H
#define LOOK_H

#include "Cmd_Base.h"
#include "../objects/Room.h"
// #include "../objects/Item.h"
// #include "../objects/Creature.h"


class Look : public Cmd_Base
{
public:
    virtual ~Look() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // LOOK_H
