#ifndef CMD_BASE_H
#define CMD_BASE_H

#include <string>
#include <vector>
#include "../World.h"

class Cmd_Base
{
public:
    virtual ~Cmd_Base() {};

    virtual std::string action(std::vector<std::string>, World&) =0;
};

#endif // CMD_BASE_H
