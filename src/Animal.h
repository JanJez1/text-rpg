#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Room.h"
#include "Creature.h"
#include "objects/Item.h"

class Animal: public Creature
{
private:
    int ac;
    int attack;
    int min_damage, max_damage;
public:
    Animal(std::string, std::string title = "hero", std::string desc = "not described");
    virtual ~Animal() = default;

    //combat related
    void set_attack(int a);
    int get_ac() override; // armour class
    int get_hr() override; // hit roll
    int get_dr() override; // damage roll
};

#endif // ANIMAL_H