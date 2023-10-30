#ifndef ROOM_DESC_H
#define ROOM_DESC_H

#include <string>
#include <memory>
#include <algorithm>
#include <map>
#include <vector>

#include "../utils.h"
#include "Special_Object.h"
#include "Creature.h"

class Room;

class Room_Desc
{
   
public:
    static std::string get_full_desc(
        const std::string &title,
        const std::string &desc,
        const std::vector<std::unique_ptr<Creature>> &creatures,
        const std::vector<std::shared_ptr<Item>> &items,
        const std::map<Exit, Room*> &exits,
        const std::map<Exit, Special_Object*> &doors
    );
};

#endif // ROOM_DESC_H
