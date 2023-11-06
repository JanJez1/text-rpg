#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Creature.h"

class Animal: public Creature
{
public:
    Animal(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Animal() = default;

    std::string get_profile() override;
    
    //combat related
    int get_ac() override; // armour class
    int get_hr() override; // hit roll
    int get_dr() override; // damage roll
};

#endif // ANIMAL_H