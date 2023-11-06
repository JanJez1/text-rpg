#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include <string>
#include <memory>

#include "objects/Player.h"
#include "defs.h"
#include "utils.h"

class Player_Factory
{
public:
    static Player create_default_player();
    static void auto_generate_abilities(Player&);
};

#endif // PLAYER_FACTORY_H