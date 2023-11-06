#ifndef PROFILE_H
#define PROFILE_H

#include "Cmd_Base.h"

class Profile : public Cmd_Base
{
public:
    virtual ~Profile() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // PROFILE_H
