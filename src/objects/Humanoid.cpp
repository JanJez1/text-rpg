#include "Humanoid.h"

using namespace std;

Humanoid::Humanoid(string key_name, string title, string desc, map<Param_Type, short> params)
    : Creature{key_name, title, desc, params}
{}

std::string Humanoid::get_profile(){
    std::string response = Creature::get_profile();
    response += "Damage:         " 
        + std::to_string( get_param(Param_Type::min_damage) + get_ability_modifier(get_param(Param_Type::str) )) +
        "/" + std::to_string( get_param(Param_Type::max_damage) + get_ability_modifier(get_param(Param_Type::str) ));
    return response;
}

int Humanoid::get_ac() { 
    short dex_modifier = get_ability_modifier(get_param(Param_Type::dex));
    short base_ac = get_param(Param_Type::ac);
    return base_ac + dex_modifier; // + worn armour
} 

int Humanoid::get_hr() {
    return random(20) + get_ability_modifier(get_param(Param_Type::str)) ;
}

int Humanoid::get_dr() {
    // no weapon equipped
    short min_damage = get_param(Param_Type::min_damage);
    short max_damage = get_param(Param_Type::max_damage);
    short str_modifier = get_ability_modifier(get_param(Param_Type::str));
    return random(min_damage, max_damage) + str_modifier;
}

string Humanoid::get_desc() {
    string output = Object::get_desc();
    string equipped_str = "";
    for(const auto& item: get_inv()) {
        if(item->is_equipped()) {
            if(item->is_wearable())
                equipped_str += "\n  " + item->get_title() + " (worn)";
            if(item->is_holdable())
                equipped_str += "\n  " + item->get_title() + " (held)";
        }
    }
    if (equipped_str.size())
        output += " " + to_upper(get_key_name()) + " has equipped:" + equipped_str;
    output += health_string();
    return output;
}

void Humanoid::add_item(string name, bool equip) {
    auto item = Item_Factory::create(name);
    if (equip) {
        item->set_equipped(true);
        for(auto const& [key, value]: item->get_item_params())
            alter_param_bonus(key, value);
    }
    m_inv.push_back(move(item));
}

std::string Humanoid::event_equip_item(Item *item) {
    // if sth already equipped on the same body part
    auto worn = find_if(m_inv.begin(), m_inv.end(),
        [&](shared_ptr<Item> & obj){
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

std::string Humanoid::event_remove_item(Item *item) {
    item->set_equipped(false);
    for(auto const& [key, value]: item->get_item_params()) {
        alter_param_bonus(key, -value);
    }
    return "You've removed " + item->get_title() + ".";
}

