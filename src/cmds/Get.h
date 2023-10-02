#ifndef GET_H
#define GET_H

#include "Cmd_Base.h"
#include "../utils.h"
#include "../World.h"
#include "../Room.h"
#include "../Object.h"
#include "../objects/Item.h"


class Get : public Cmd_Base
{
public:
    virtual ~Get() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // GET_H
