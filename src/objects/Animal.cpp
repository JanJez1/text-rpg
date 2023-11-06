#include "Animal.h"

using namespace std;

Animal::Animal(string key_name, string title, string desc, map<Param_Type, short> params)
    : Creature{key_name, title, desc, params}
{}

std::string Animal::get_profile(){
    std::string response = Creature::get_profile();
    response += "Damage:        " 
        + std::to_string( get_param(Param_Type::min_damage) ) +
        "/" + std::to_string( get_param(Param_Type::max_damage) );
    return response;
}


int Animal::get_ac() { 
    short dex_modifier = get_ability_modifier(get_param(Param_Type::dex));
    short base_ac = get_param(Param_Type::ac);
    return base_ac + dex_modifier;
} 

int Animal::get_hr() {
    return get_param(Param_Type::attack) + random(20);
}

int Animal::get_dr() {
    short min_damage = get_param(Param_Type::min_damage);
    short max_damage = get_param(Param_Type::max_damage);
    return random(min_damage, max_damage);
}