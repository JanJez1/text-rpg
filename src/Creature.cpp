#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc, map<Param_Type, short> params)
    : Object{key_name, title, desc},
      base_params{params},
      param_bonuses{}
{
}

void Creature::alter_param_bonus(Param_Type param_type, short value) {
    auto itr = param_bonuses.find(param_type);
    if (itr != param_bonuses.end())
        itr->second += value;
    else
        param_bonuses[param_type] = value;
}

short Creature::get_param(Param_Type param_type) {
    short param_value {0};
    auto itr = base_params.find(param_type);
    if (itr != base_params.end())
        param_value += itr->second;
    itr = param_bonuses.find(param_type); // change this line or next line!!
    if (param_bonuses.find(param_type) != param_bonuses.end())
        param_value += param_bonuses.at(param_type);
    return param_value;
}

void Creature::add_item(std::unique_ptr<Item> item) {
    m_inv.push_back(move(item));
}

void Creature::alter_hp(int change) {
    if ( (hp + change) > get_param(Param_Type::max_hp)) {
        hp = get_param(Param_Type::max_hp);
        return;
    }
    hp += change;
    if (hp < 0) {} //event_die()
}

// item manipulation
// iter to items in room
string Creature::event_pick_item(vector<unique_ptr<Item>>::iterator iter) {
    string response = "You've picked up " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        m_inv.push_back(move(*iter));
        get_current_room()->get_items().erase(iter);
    }
    return response;
}

// iter to inventory
string Creature::event_drop_item(vector<unique_ptr<Item>>::iterator iter) {
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

std::string Creature::event_wear_item(vector<unique_ptr<Item>>::iterator iter) {
    // if sth already equipped on the same body part
    auto worn = find_if(m_inv.begin(), m_inv.end(),
        [&](unique_ptr<Item> & obj){
        return (obj->is_equipped() && obj->get_object_type() == (*iter)->get_object_type());
    });
    string response = "";
    if(worn != m_inv.end()) {
        response = event_remove_item(worn) + "\n";
    }

    (*iter)->set_equipped(true);
    for(auto const& [key, value]: (*iter)->get_item_params()) {
        alter_param_bonus(key, value);
    }
    return response += "You've worn " + (*iter)->get_title() + ".";
}

std::string Creature::event_remove_item(vector<unique_ptr<Item>>::iterator iter) {
    (*iter)->set_equipped(false);
    for(auto const& [key, value]: (*iter)->get_item_params()) {
        alter_param_bonus(key, -value);
    }
    return "You've removed " + (*iter)->get_title() + ".";
}


std::string ability_value_to_string(short value) {
    std::string str = std::to_string(value) + " ";
    short modif = ( value - 10 ) / 2;
    if (modif == 0)
        return str;
    str += "(";
    if (modif > 0)
        str += "+";
    return str += std::to_string(modif) + ")";
}

std::string Creature::get_status(){
    std::string response = "";
    response += "Strength:      " + ability_value_to_string(get_param(Param_Type::str)) + "\n";
    response += "Dexterity:     " + ability_value_to_string(get_param(Param_Type::dex)) + "\n";
    response += "Constitution:  " + ability_value_to_string(get_param(Param_Type::con)) + "\n";
    response += "Health points: " + std::to_string(get_param(Param_Type::max_hp)) + "/" + std::to_string(get_param(Param_Type::max_hp)) + "\n";
    response += "Damage:        " + std::to_string(get_param(Param_Type::min_damage)) + "/" + std::to_string(get_param(Param_Type::max_damage)) + "\n";;
    response += "Armour class:  " + std::to_string(get_param(Param_Type::ac));
    return response;
}