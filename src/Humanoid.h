#ifndef HUMANOID_H
#define HUMANOID_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Room.h"
#include "Creature.h"
#include "objects/Item.h"

class Humanoid: public Creature
{
private:
    int ac;
    int attack;
    int min_damage, max_damage;
public:
    Humanoid(std::string, std::string title = "hero", std::string desc = "not described");
    virtual ~Humanoid() = default;

    //combat related
    int get_ac() override; // armour class
    int get_hr() override; // hit roll
    int get_dr() override; // damage roll
};

#endif // HUMANOID_H