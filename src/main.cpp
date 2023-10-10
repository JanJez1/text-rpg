#include <iostream>
#include <memory>
#include <map>
#include <string>

#include "defs.h"
#include "World.h"
#include "Player.h"
#include "utils.h"
#include "Input_Handler.h"
#include "Commands.h"
using namespace std;

int main() {

 // ToDo
 // - initialization of the game - name of player, setting stats etc.
 // - extract some code from main.cpp somewhere else
   
     map<Param_Type, short> default_player_params {
        {Param_Type::str, 7},
        {Param_Type::dex, 10},
        {Param_Type::con, 15}
     };

    Player player{"Dorban", "player", "A young barbarian.", default_player_params};
    World world{};
    player.set_current_room(world.get_start_room());
    string input_line = "";
    Input_Handler input_handler {};
    Commands commands{};
    vector<string> tokens{};
    string response="";
    
    cout << player.get_current_room()->get_full_desc() << endl;
    
    // main game loop
    do {
        cout << "> ";
        getline (cin, input_line);
        input_handler.parse_input(input_line);
        tokens = input_handler.get_tokens();
        response = commands.execute_command(tokens, player);
        cout << response << endl;
    }
    while (player.is_playing());
	return 0;
}

