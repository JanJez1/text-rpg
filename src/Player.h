#ifndef PLAYER_H
#define PLAYER_H

#include <string>
// #include <vector>
#include <map>
// #include <memory>

#include "Room.h"
#include "Humanoid.h"
#include "objects/Item.h"

class Player: public Humanoid
{
private:
    Room* current_room;
    bool playing;
public:
    Player(std::string key_name, std::string title, std::string desc, std::map<Param_Type, short> params);
    virtual ~Player() = default;
    void set_current_room(Room* room) {current_room = room;}
    Room* get_current_room()  {return current_room;}
    bool is_playing() { return playing; }
    void quit_game() { playing = false; }

    std::string event_drop_item(std::vector<std::unique_ptr<Item>>::iterator); // only for player
    std::string event_pick_item(std::vector<std::unique_ptr<Item>>::iterator); // only for player
};

#endif // PLAYER_H