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
protected:
    short str, dex, con;
    int hp, max_hp;
public:
    Creature(std::string, std::string title = "unknown", std::string desc = "not described");
    virtual ~Creature() = default;

    // settings
    void set_abilities(short str=1, short dex=1, short con=1);
    short get_ability_modifier(short ability) { return ( ability-10 ) / 2; }
    void set_max_hp(int, bool reset_actual_hp = false);


    void add_item(std::unique_ptr<Object>);
    std::vector<std::unique_ptr<Object>>& get_inv() { return m_inv; };

    // combat related
    void add_hp(int change);
    virtual int get_ac() = 0; // armour class
    virtual int get_hr() = 0; // hit roll
    virtual int get_dr() = 0; // damage roll

    // item manipulation
    std::string event_drop_item(std::vector<std::unique_ptr<Object>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::unique_ptr<Object>>::iterator); // only for player
    std::string event_wear_item(std::vector<std::unique_ptr<Object>>::iterator);
    std::string event_remove_item(std::vector<std::unique_ptr<Object>>::iterator);

    // overrides
    virtual Room* get_current_room() {return nullptr;}
};

#endif // CREATURE_H