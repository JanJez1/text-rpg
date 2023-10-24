#ifndef WEAR_H
#define WEAR_H

#include "Cmd_Base.h"
#include "../utils.h"
// #include "../Object.h"
#include "../objects/Item.h"


class Wear : public Cmd_Base
{
public:
    virtual ~Wear() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // WEAR_H
