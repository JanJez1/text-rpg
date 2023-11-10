#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc, map<Param_Type, short> params)
    : Object{key_name, title, desc},
      base_params{params},
      param_bonuses{},
      m_inv{},
      position{"standing"}
{    
    auto iter = base_params.find(Param_Type::max_hp);
    if(iter == base_params.end()) {
        hp = 10;
        base_params.insert({Param_Type::max_hp, hp});
    }
    else
        hp = iter->second;
}



// DESCRIPTION, PROFILE

string Creature::get_abilities_profile(){
    std::string response = "\n";
    response += "Strength:       " + ability_to_string(get_param_incl_bonus(Param_Type::str)) + "\n";
    response += "Dexterity:      " + ability_to_string(get_param_incl_bonus(Param_Type::dex)) + "\n";
    response += "Constitution:   " + ability_to_string(get_param_incl_bonus(Param_Type::con)) + "\n";
    return response;
}

string Creature::get_profile(){
    std::string response = get_abilities_profile();
    response += "Health points:  " + std::to_string(hp) + "/" + std::to_string(get_param_incl_bonus(Param_Type::max_hp)) + "\n";
    response += "Armour class:   " + std::to_string(get_param_incl_bonus(Param_Type::ac)) + "\n";
    return response;
}

string Creature::get_desc() {
    return Object::get_desc() + health_string();
}

string Creature::health_string() {
    int health_percentage = 100 * get_hp() / get_param_incl_bonus(Param_Type::max_hp);
    string str = "\n" + to_upper(get_key_name()) + " is ";
    if (health_percentage > 99)
        return  str + "in full health.";
    if (health_percentage > 90)
        return  str + "almost in full health.";
    if (health_percentage > 70)
        return  str + "slightly scratched.";
    if (health_percentage > 50)
        return  str + "injured.";
    if (health_percentage > 30)
        return  str + "badly injured.";
    if (health_percentage > 10)
        return  str + "very seriously injured.";
    return str + "almost dead.";
}

// ----------------------------------

void Creature::alter_param_bonus(Param_Type param_type, short value) {
    auto itr = param_bonuses.find(param_type);
    if (itr != param_bonuses.end())
        itr->second += value;
    else
        param_bonuses[param_type] = value;
}

short Creature::get_param_incl_bonus(Param_Type param_type) {
    short param_value = get_base_param(param_type);
    auto itr = param_bonuses.find(param_type); 
    if (itr != param_bonuses.end())
        param_value += itr->second;
    return param_value;
}

short Creature::get_base_param(Param_Type param_type) {
    auto itr = base_params.find(param_type);
    if (itr != base_params.end())
        return itr->second;
    return 0;
}

void Creature::raise_base_param(Param_Type param_type, short value) {
    auto itr = base_params.find(param_type);
    if (itr == base_params.end())
        base_params.insert({param_type, value});
    else 
        base_params.at(param_type) += value;
}


void Creature::add_item(string name, bool equip) {
    auto item = Item_Factory::create(name);
    m_inv.push_back(move(item));
}

Item *Creature::find_item(std::string name) {
    auto iter = find_elem(name, m_inv);
    if (iter == m_inv.end())
        return nullptr;
    return (*iter).get();
}

void Creature::alter_hp(int change) {
    if ( (hp + change) > get_param_incl_bonus(Param_Type::max_hp)) {
        hp = get_param_incl_bonus(Param_Type::max_hp);
        return;
    }
    hp += change;
    if (hp < 0) {} //event_die()
}

string Creature::die() {  // 
    return to_upper(get_key_name() + " drops dead.");
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





