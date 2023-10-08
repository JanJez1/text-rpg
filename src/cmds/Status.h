#ifndef STATUS_H
#define STATUS_H

#include "Cmd_Base.h"
#include "../World.h"
#include "../Room.h"
#include "../objects/Item.h"


class Status : public Cmd_Base
{
public:
    virtual ~Status() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // LOOK_H
