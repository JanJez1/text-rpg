#ifndef CHEST_H
#define CHEST_H

#include <string>
#include <list>

#include "../defs.h"
#include "../objects/Special_Object.h"
#include "../objects/Room.h"

class Chest: public Special_Object
{
private:
    std::string name_of_key;
    std::list<std::string> items;
public:
    Chest(std::string name, std::string title, std::string desc, Room* current_room_, std::string name_of_key);
    virtual ~Chest() = default;

    void add_item(std::string item) { items.push_back(item); }

    std::string event_unlock() override;
    std::string get_action_item() override { return name_of_key;}
    std::string get_desc() override;
    bool is_visible() override { return true; }
    
};

#endif // CHEST_H