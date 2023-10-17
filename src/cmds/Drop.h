#ifndef DROP_H
#define DROP_H

#include "Cmd_Base.h"
#include "../utils.h"
#include "../Object.h"
#include "../objects/Item.h"

class Drop : public Cmd_Base
{
public:
    virtual ~Drop() {};
    virtual std::string action(std::vector<std::string>, Player&) override;
};

#endif // DROP_H
