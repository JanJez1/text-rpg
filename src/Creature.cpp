#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc)
    : Object{key_name, title, desc},
      m_inv{},
      str{1}, dex{1}, con{1},
      hp{10}, max_hp{10}
{
}

// settings
    short apply_ability_limits(short ability) {
        if (ability < 1) return 1;
        if (ability > 30) return 30;
        return ability;
    }

    void Creature::set_abilities(short strength, short dexterity, short constitution) {
        str = apply_ability_limits(strength);
        dex = apply_ability_limits(dexterity);
        con = apply_ability_limits(constitution);
    }

    void Creature::set_max_hp(int max_health, bool reset_actual_hp) {
        if (max_health <1) 
            max_hp = 1;
        max_hp = max_health;
        if (reset_actual_hp) 
            hp = max_health;
    }


void Creature::add_item(std::unique_ptr<Object> item) {
    m_inv.push_back(move(item));
}


void Creature::add_hp(int change) {
    if ( (hp + change) > max_hp) {
        hp = max_hp;
        return;
    }
    hp += change;
    if (hp < 0) {} //event_die()
}

// item manipulation
// iter to items in room
string Creature::event_pick_item(vector<unique_ptr<Object>>::iterator iter) {
    string response = "You've picked up " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        m_inv.push_back(move(*iter));
        get_current_room()->get_items().erase(iter);
    }
    return response;
}

// iter to inventory
string Creature::event_drop_item(vector<unique_ptr<Object>>::iterator iter) {
    string response = "";
    if ((*iter)->is_equipped())
        response = event_remove_item(iter) + "\n";
    
    response += "You've dropped " + (*iter)->get_title() + "."; 
    // ToDo: add try / catch to be sure
    if (get_current_room() != nullptr) { 
        get_current_room()->add_item(move(*iter));
        m_inv.erase(iter);
    }

    return response;
}

std::string Creature::event_wear_item(vector<unique_ptr<Object>>::iterator iter) {
    // if sth already equipped on the same body part
    auto worn = find_if(m_inv.begin(), m_inv.end(),
        [&](unique_ptr<Object> & obj){
        return (obj->is_equipped() && obj->get_object_type() == (*iter)->get_object_type());
    });
    string response = "";
    if(worn != m_inv.end()) {
        response = event_remove_item(worn) + "\n";
    }

    (*iter)->set_equipped(true);
    return response += "You've worn " + (*iter)->get_title() + ".";
}

std::string Creature::event_remove_item(vector<unique_ptr<Object>>::iterator iter) {
    (*iter)->set_equipped(false);
    return "You've removed " + (*iter)->get_title() + ".";
}
