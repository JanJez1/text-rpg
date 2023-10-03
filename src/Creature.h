#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

#include "Object.h"
#include "Room.h"
#include "utils.h"
#include "defs.h"
#include "objects/Item.h"


class Creature: public Object
{
private:
    std::vector<std::unique_ptr<Object>> m_inv;

public:
    Creature(std::string, std::string title = "unknown", std::string desc = "not described");
    virtual ~Creature() = default;

    void add_item(std::unique_ptr<Object>);
    std::vector<std::unique_ptr<Object>>& get_inv() { return m_inv; };

    std::string event_drop_item(std::vector<std::unique_ptr<Object>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::unique_ptr<Object>>::iterator); // only for player
    std::string event_wear_item(std::vector<std::unique_ptr<Object>>::iterator);
    std::string event_remove_item(std::vector<std::unique_ptr<Object>>::iterator);

    // overrides
    virtual Room* get_current_room() {return nullptr;}
};

#endif // CREATURE_H