#ifndef GO_H
#define GO_H

#include "Cmd_Base.h"
// #include "../World.h"
#include "../utils.h"
#include "../special_objects/Door.h"

class Go : public Cmd_Base
{
public:
    virtual ~Go() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // GO_H
