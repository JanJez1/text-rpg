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
    bool playing;
    int exp;
    int lvl;
    std::string level_up();
    std::string raise_exp(Creature &creature);
public:
    Player(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Player() = default;

    std::string get_status() override;

    std::string creature_killed(Creature &creature);
    int get_exp() { return exp; }

    void set_current_room(Room* room) {current_room = room;}
    Room* get_current_room()  {return current_room;}
    bool is_playing() { return playing; }
    void quit_game() { playing = false; }

    std::string event_drop_item(std::vector<std::shared_ptr<Item>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::shared_ptr<Item>>::iterator); // only for player
};

#endif // PLAYER_H