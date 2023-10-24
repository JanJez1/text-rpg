#ifndef DOOR_H
#define DOOR_H

#include <string>

#include "../defs.h"
#include "../objects/Special_Object.h"

class Door: public Special_Object
{
private:
    std::string name_of_key;
public:
    Door(std::string name, std::string desc, std::string name_of_key_);
    virtual ~Door() = default;

    std::string event_unlock() override;
    std::string get_action_item() override { return name_of_key;}
    std::string get_desc() override;
};

#endif // DOOR_H