#ifndef HOLD_H
#define HOLD_H

#include "Cmd_Base.h"
#include "../utils.h"
#include "../objects/Item.h"

class Hold : public Cmd_Base
{
public:
    virtual ~Hold() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // HOLD_H
