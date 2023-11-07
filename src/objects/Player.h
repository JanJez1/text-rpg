#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

#include "Room.h"
#include "Humanoid.h"
#include "../utils.h"

class Player: public Humanoid
{
private:
    Room* current_room;
    Player_State state; // logged, dead
    int exp;
    int lvl;
    std::string level_up();
    std::string raise_exp(Creature &creature);
public:
    // Player(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    Player(std::map<Param_Type, short> params);
    virtual ~Player() = default;

    Player_State get_state() { return state; }
    void set_state(Player_State st) { state = st; }
    int get_level() { return lvl; }

    std::string get_profile() override; // show str, dex, hp

    std::string creature_killed(Creature &creature);
    int get_exp() { return exp; }
    void event_die();

    void set_current_room(Room* room) {current_room = room;}
    Room* get_current_room()  {return current_room;}

    std::string event_drop_item(std::vector<std::shared_ptr<Item>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::shared_ptr<Item>>::iterator); // only for player
};

#endif // PLAYER_H