#ifndef QUIT_H
#define QUIT_H

#include "Cmd_Base.h"

class Quit : public Cmd_Base
{
public:
    virtual ~Quit() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // QUIT_H
