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
    std::vector<std::unique_ptr<Item>> m_inv;
protected:
    short hp;
    std::map<Param_Type, short> base_params;

public:
    Creature(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Creature() = default;

    short get_ability_modifier(short ability_value) { return ( ability_value-10 ) / 2; }

    void add_item(std::unique_ptr<Item>);
    std::vector<std::unique_ptr<Item>>& get_inv() { return m_inv; };

    // combat related
    void add_hp(int change);
    virtual int get_ac() = 0; // armour class
    virtual int get_hr() = 0; // hit roll
    virtual int get_dr() = 0; // damage roll
    short get_param(Param_Type);

    // item manipulation - move to humanoid!!
    std::string event_drop_item(std::vector<std::unique_ptr<Item>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::unique_ptr<Item>>::iterator); // only for player
    std::string event_wear_item(std::vector<std::unique_ptr<Item>>::iterator);
    std::string event_remove_item(std::vector<std::unique_ptr<Item>>::iterator);

    std::string display_status(); // in production should be in player, it is here to check monsters during  development

    // overrides
    virtual Room* get_current_room() {return nullptr;}
};

#endif // CREATURE_H