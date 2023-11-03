#ifndef HUMANOID_H
#define HUMANOID_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "../defs.h"
#include "Creature.h"

class Humanoid: public Creature
{
private:
    int ac;
    int attack;
    int min_damage, max_damage;
public:
    Humanoid(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Humanoid() = default;

    std::string get_status() override;
    
    //combat related
    int get_ac() override; // armour class
    int get_hr() override; // hit roll
    int get_dr() override; // damage roll

    // equipped items related
    std::string get_desc() override; //desc + equipped items
    void add_item(std::string, bool equip = false) override;
    std::string event_equip_item(Item*);
    std::string event_remove_item(Item*);

};

#endif // HUMANOID_H