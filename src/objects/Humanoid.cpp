#include "Humanoid.h"

using namespace std;

Humanoid::Humanoid(string key_name, string title, string desc, map<Param_Type, short> params)
    : Creature{key_name, title, desc, params}
{}

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
    // weapon equipped:
}

string Humanoid::get_desc() {
    string output = Creature::get_desc();
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
    return output;
}