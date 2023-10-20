#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc, map<Param_Type, short> params)
    : Object{key_name, title, desc},
      base_params{params},
      param_bonuses{},
      m_inv{}
{    
    map<Param_Type, short>::const_iterator iter = base_params.find(Param_Type::max_hp);
    if(iter == base_params.end()) {
        hp = 10;
        base_params.insert({Param_Type::max_hp, hp});
    }
    else
        hp = iter->second;
}

void Creature::alter_param_bonus(Param_Type param_type, short value) {
    auto itr = param_bonuses.find(param_type);
    if (itr != param_bonuses.end())
        itr->second += value;
    else
        param_bonuses[param_type] = value;
}


// I made changes here 13.10
short Creature::get_param(Param_Type param_type) {
    short param_value {0};
    auto itr = base_params.find(param_type);
    if (itr != base_params.end())
        param_value += itr->second;
    auto itr2 = param_bonuses.find(param_type); 
    if (itr2 != param_bonuses.end())
        param_value += itr2->second;
    return param_value;
}

void Creature::add_item(string name, bool equip) {
    auto item = Item_Factory::create(name);
    if (equip) {
        item->set_equipped(true);
        for(auto const& [key, value]: item->get_item_params())
            alter_param_bonus(key, value);
    }
    m_inv.push_back(move(item));
}

Item *Creature::find_item(std::string name) {
    auto iter = find_elem(name, m_inv);
    if (iter == m_inv.end())
        return nullptr;
    return (*iter).get();
}

void Creature::alter_hp(int change) {
    if ( (hp + change) > get_param(Param_Type::max_hp)) {
        hp = get_param(Param_Type::max_hp);
        return;
    }
    hp += change;
    if (hp < 0) {} //event_die()
}

string Creature::die() {  // 
    return to_upper(get_key_name() + " drops dead.");
}


std::string Creature::event_equip_item(Item *item) {
    // if sth already equipped on the same body part
    auto worn = find_if(m_inv.begin(), m_inv.end(),
        [&](unique_ptr<Item> & obj){
        return (obj->is_equipped() && obj->get_object_type() == item->get_object_type());
    });
    string response = "";
    if(worn != m_inv.end()) {
        response = event_remove_item((*worn).get()) + "\n";
    }

    item->set_equipped(true);
    for(auto const& [key, value]: item->get_item_params()) {
        alter_param_bonus(key, value);
    }
    if (item->is_wearable())
        return response += "You've worn " + item->get_title() + ".";
    return response += "You've held " + item->get_title() + ".";
}

std::string Creature::event_remove_item(Item *item) {
    item->set_equipped(false);
    for(auto const& [key, value]: item->get_item_params()) {
        alter_param_bonus(key, -value);
    }
    return "You've removed " + item->get_title() + ".";
}

// --------- SUPPORT
std::string Creature::ability_to_string(short value) {
    std::string str = std::to_string(value) + " ";
    short modif = get_ability_modifier(value);
    if (modif == 0)
        return str;
    str += "(";
    if (modif > 0)
        str += "+";
    return str += std::to_string(modif) + ")";
}

std::string Creature::get_status(){
    short strength = get_param(Param_Type::str);
    std::string response = "";
    response += "Strength:      " + ability_to_string(strength) + "\n";
    response += "Dexterity:     " + ability_to_string(get_param(Param_Type::dex)) + "\n";
    response += "Constitution:  " + ability_to_string(get_param(Param_Type::con)) + "\n";
    response += "Health points: " + std::to_string(hp) + "/" + std::to_string(get_param(Param_Type::max_hp)) + "\n";
    response += "Damage:        " 
        + std::to_string( get_param(Param_Type::min_damage) + get_ability_modifier(strength) ) +
        "/" + std::to_string( get_param(Param_Type::max_damage) + get_ability_modifier(strength) ) + "\n";;
    response += "Armour class:  " + std::to_string(get_param(Param_Type::ac));
    return response;
}



