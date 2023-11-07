#ifndef RAISE_H
#define RAISE_H

#include <stdexcept>

#include "Cmd_Base.h"

class Raise : public Cmd_Base
{
public:
    virtual ~Raise() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
    int get_ability_max(int level);
};

#endif // RAISE_H
