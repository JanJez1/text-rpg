#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Room.h"
#include "Creature.h"
#include "objects/Item.h"

class Player: public Creature
{
private:
    Room* current_room;
public:
    Player(std::string, std::string title = "hero", std::string desc = "not described");
    virtual ~Player() = default;
    void set_current_room(Room* room) {current_room = room;}
    Room* get_current_room() override {return current_room;}
};

#endif // PLAYER_H