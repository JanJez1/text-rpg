#include <iostream>
#include <memory>
#include <string>

#include "World.h"
#include "utils.h"
#include "Input_Handler.h"
#include "Commands.h"

using namespace std;

int main() {

 // ToDo initialization of the game - name of player, setting stats etc.
   
    World world;
    string input_line = "";
    Input_Handler input_handler {};
    Commands commands{};
    vector<string> tokens{};
    string response="";
    
    cout << world.get_current_room()->get_full_desc() << endl;
    
    // main game loop
    do {
        cout << "> ";
        getline (cin, input_line);
        input_handler.parse_input(input_line);
        tokens = input_handler.get_tokens();
            // I need to pass object 'world' to the command 
            // as most of the commands need to use or even change current_room
        response = commands.execute_command(tokens, world);
        cout << response << endl;
    }
    while (input_line != "q" && input_line != "quit");
    cout << "Thanks for playing!" << endl;
	return 0;
}

