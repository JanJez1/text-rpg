#include "Player.h"

using namespace std;

Player::Player(string key_name, string title, string desc, map<Param_Type, short> params)
    : Humanoid{key_name, title, desc, params},
    playing{true}
{}


// iter to items in room
string Player::event_pick_item(vector<shared_ptr<Item>>::iterator iter) {
    string response = "You've picked up " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        get_inv().push_back(move(*iter));
        get_current_room()->get_items().erase(iter);
    }
    return response;
}

// iter to inventory
string Player::event_drop_item(vector<shared_ptr<Item>>::iterator iter) {
    string response = "";
    if ((*iter)->is_equipped())
        response = event_remove_item((*iter).get()) + "\n";
    
    response += "You've dropped " + (*iter)->get_title() + "."; 
    // ToDo: add try / catch to be sure
    if (get_current_room() != nullptr) { 
        get_current_room()->add_item(move(*iter));
        get_inv().erase(iter);
    }

    return response;
}