#ifndef UNLOCK_H
#define UNLOCK_H

#include "Cmd_Base.h"
#include "../utils.h"
#include "../objects/Item.h"
#include <memory>
#include <algorithm>

class Unlock : public Cmd_Base
{
public:
    virtual ~Unlock() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // UNLOCK_H
