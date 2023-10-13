#ifndef REMOVE_H
#define REMOVE_H

#include "Cmd_Base.h"
#include "../utils.h"
// #include "../World.h"
#include "../Object.h"
#include "../objects/Item.h"


class Remove : public Cmd_Base
{
public:
    virtual ~Remove() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // REMOVE_H
