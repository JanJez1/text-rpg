#ifndef HIDDEN_EXIT_H
#define HIDDEN_EXIT_H

#include <string>

#include "../defs.h"
#include "../objects/Special_Object.h"
#include "../objects/Room.h"

class Hidden_Exit: public Special_Object
{
public:
    Hidden_Exit(std::string key_name, std::string desc, Room* current_room_, Room* target_room_);
    virtual ~Hidden_Exit() = default;

    std::string event_look() override;
};

#endif // HIDDEN_EXIT_H