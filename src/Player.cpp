#include "Player.h"

using namespace std;

Player::Player(string key_name, string title, string desc, map<Param_Type, short> params)
    : Humanoid{key_name, title, desc, params},
    playing{true}
{}


