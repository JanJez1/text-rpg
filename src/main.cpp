#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <cstdlib>

#include "defs.h"
#include "main_menu/Main_Menu.h"
#include "main_menu/Player_Factory.h"
#include "objects/Player.h"
#include "utils.h"
#include "Input_Handler.h"
#include "Commands.h"
#include "world_helper/Room_Factory.h"


using namespace std;

int main() {
    auto selection{Menu_Item::in_menu};
    do {

        // *** MAIN MENU ***
        selection = Main_Menu::select_menu_item();
        if (selection != Menu_Item::quit) {
            auto player = Player_Factory::create_default_player();
            if (selection == Menu_Item::auto_generate) {
                Player_Factory::auto_generate_abilities(player);
            }
            else if (selection == Menu_Item::generate) {
            }

            // *** GAME INIT ***
            srand(time(0));
            Room_Factory room_factory{};
            room_factory.generate_rooms();
            player.set_current_room(room_factory.get_start_room());
            player.set_state(Player_State::playing);
            
            string input_line = "";
            Input_Handler input_handler {};
            Commands commands{};
            vector<string> tokens{};
            string response="";
            
            cout << player.get_current_room()->get_full_desc() << endl;
            
            // *** MAIN GAME LOOP ***
            do {
                cout << "> ";
                getline (cin, input_line);
                input_handler.parse_input(input_line);
                tokens = input_handler.get_tokens();
                response = commands.execute_command(tokens, player);
                cout << response << endl;
            }
            while (player.get_state() == Player_State::playing);
        }
    }
    while (selection != Menu_Item::quit);
    return 0;
}