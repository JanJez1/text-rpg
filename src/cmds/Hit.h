#ifndef HIT_H
#define HIT_H

#include "Cmd_Base.h"
#include "../Combat.h"
#include "../utils.h"
#include "../Object.h"
#include "../objects/Item.h"

class Hit : public Cmd_Base
{
public:
    virtual ~Hit() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // HIT_H
