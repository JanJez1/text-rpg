#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

#include "../Object.h"
#include "../utils.h"
#include "../defs.h"
#include "Item.h"
#include "../world_helper/Item_Factory.h"


class Creature: public Object
{
  
protected:
    short hp;
    std::map<Param_Type, short> base_params;
    std::map<Param_Type, short> param_bonuses;
    std::vector<std::shared_ptr<Item>> m_inv;
    std::string position;

public:
    Creature(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Creature() = default;

    short get_ability_modifier(short ability_value) { return ( ability_value-10 ) / 2; }
    std::string ability_to_string(short value);

    void add_item(std::string, bool equip = false);
    Item *find_item(std::string);
    std::vector<std::shared_ptr<Item>>& get_inv() { return m_inv; }; 

    // combat related
    void alter_hp(int change);
    short get_hp() { return hp; };
    virtual int get_ac() = 0; // armour class
    virtual int get_hr() = 0; // hit roll
    virtual int get_dr() = 0; // damage roll
    virtual std::string die();

    void set_base_param(Param_Type param_type, short value) {
        base_params.insert_or_assign(param_type, value);
    }
    void alter_param_bonus(Param_Type, short);
    short get_param(Param_Type);

    std::string event_equip_item(Item*);
    std::string event_remove_item(Item*);
    std::string event_heal();

    std::string get_status();
    std::string get_position() { return position;};
    void set_position(std::string pos) { position = pos; };
};

#endif // CREATURE_H