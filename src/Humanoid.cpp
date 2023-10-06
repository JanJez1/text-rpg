#include "Humanoid.h"

using namespace std;

Humanoid::Humanoid(string key_name, string title, string desc)
    : Creature{key_name, title, desc}
{}

int Humanoid::get_ac() { 
    return ac + get_ability_modifier(dex);
} 

int Humanoid::get_hr() {
    return random(20) + get_ability_modifier(str) ;
}

int Humanoid::get_dr() {
    return random(min_damage, max_damage) + get_ability_modifier(str);
}