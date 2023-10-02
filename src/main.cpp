#include <iostream>
#include <memory>
#include <string>

#include "World.h"
#include "Player.h"
#include "utils.h"
#include "Input_Handler.h"
#include "Commands.h"
// #include "objects/Item_Factory.h"
using namespace std;

int main() {

 // ToDo
 // - initialization of the game - name of player, setting stats etc.
 // - extract some code from main.cpp somewhere else
 // - make a "quit" command rather than this :-)
   
    
    Player player{"hero"};
    World world{};
    player.set_current_room(world.get_start_room());
    string input_line = "";
    Input_Handler input_handler {};
    Commands commands{};
    vector<string> tokens{};
    string response="";
    
    cout << player.get_current_room()->get_full_desc() << endl;

    // Item_Factory fact{};

    
    // main game loop
    do {
        cout << "> ";
        getline (cin, input_line);
        input_handler.parse_input(input_line);
        tokens = input_handler.get_tokens();
        response = commands.execute_command(tokens, player);
        cout << response << endl;
    }
    while (input_line != "q" && input_line != "quit");
    cout << "Thanks for playing!" << endl;
	return 0;
}

