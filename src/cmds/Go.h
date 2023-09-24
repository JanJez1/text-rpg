#ifndef GO_H
#define GO_H

#include "Cmd_Base.h"
#include "../World.h"
#include "../utils.h"

class Go : public Cmd_Base
{
public:
    virtual ~Go() {};
    virtual std::string action(std::vector<std::string>, World&) override;
};

#endif // GO_H
