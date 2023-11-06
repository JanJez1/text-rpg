#include "Player.h"

using namespace std;

// Player::Player(string key_name, string title, string desc, map<Param_Type, short> params)
Player::Player(map<Param_Type, short> params)
    : Humanoid{"", "you", "", params},
    state{Player_State::in_menu},
    playing{true},
    alive{true},
    exp{0},
    lvl{1}
{}

// COMBAT RELATED
string Player::creature_killed(Creature &creature) {
    current_room->creature_killed(creature); // 'removes' creature and drops its inventory
    return raise_exp(creature);
}

string Player::raise_exp(Creature &creature) {
    exp += creature.get_param(Param_Type::exp_rating);
    if (exp > exp_to_advance(lvl) )
        return level_up();
    return ""; 
}

string Player::level_up() {
    int con_modif = get_ability_modifier(base_params.at(Param_Type::con));
    base_params.at(Param_Type::max_hp) += con_modif + 6;
    hp = base_params.at(Param_Type::max_hp);
    lvl++;
    // ToDo raise 2 abilities
    return "\nYou gained another level!";
}

void Player::event_die() {
    state = Player_State::dead;
}

// ITEM MANIPULATION
string Player::event_pick_item(vector<shared_ptr<Item>>::iterator iter) { // iter to items in room
    string response = "You've picked up " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        get_inv().push_back(move(*iter));
        get_current_room()->get_items().erase(iter);
    }
    return response;
}

string Player::event_drop_item(vector<shared_ptr<Item>>::iterator iter) { // iter to inventory
    string response = "";
    if ((*iter)->is_equipped())
        response = event_remove_item((*iter).get()) + "\n";
    
    response += "You've dropped " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        get_current_room()->add_item(move(*iter));
        get_inv().erase(iter);
    }
    return response;
}

// DESCRIPTION

string Player::get_profile() {
    string response = Humanoid::get_profile() + "\n";
    response += "Level: " + std::to_string(lvl)+ "\n";
    response += "Experience: " + std::to_string(exp) + "/" + std::to_string(exp_to_advance(lvl));
    return response;
}