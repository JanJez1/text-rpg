#ifndef CREATURE_FACTORY_H
#define CREATURE_FACTORY_H

#include <string>
#include <memory>

#include "../objects/Humanoid.h"
#include "../objects/Animal.h"
#include "../defs.h"
#include "../utils.h"

class Creature_Factory
{
public:
    static std::unique_ptr<Creature> create(std::string);
};

#endif // CREATURE_FACTORY_H