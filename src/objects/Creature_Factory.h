#ifndef CREATURE_FACTORY_H
#define CREATURE_FACTORY_H

#include <string>
#include <memory>

#include "../Creature.h"
#include "../Humanoid.h"
#include "../Animal.h"
#include "../defs.h"
#include "Item_Factory.h"

class Creature_Factory
{
public:
    std::unique_ptr<Creature> create(std::string);
};

#endif // CREATURE_FACTORY_H