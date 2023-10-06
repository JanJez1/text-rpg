#include "Animal.h"

using namespace std;

Animal::Animal(string key_name, string title, string desc)
    : Creature{key_name, title, desc}
{}

void Animal::set_attack(int a) { 
    if (a < 0) { attack = 0; return; }
    if (a > 30) { attack = 30; return; }
    attack = a;
}

int Animal::get_ac() { 
    return ac + get_ability_modifier(dex);
} 

int Animal::get_hr() {
    return attack + random(20);
}

int Animal::get_dr() {
    return random(min_damage, max_damage);
}