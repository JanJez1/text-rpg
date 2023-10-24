#ifndef COMBAT_H
#define COMBAT_H

#include <string>

#include "objects/Creature.h"
#include "objects/Player.h"


class Combat
{
private:
    /* data */
public:
    std::string compute_round(Player&, Creature&);
};



#endif // COMBAT_H