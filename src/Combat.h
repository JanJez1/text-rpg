#ifndef COMBAT_H
#define COMBAT_H

#include <string>
// #include <message>

#include "Creature.h"
#include "Player.h"


class Combat
{
private:
    /* data */
public:
    std::string compute_round(Player&, Creature&);
};



#endif // COMBAT_H