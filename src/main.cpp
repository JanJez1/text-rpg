#include <string>

#include "defs.h"
#include "main_menu/Main_Menu.h"
#include "main_menu/Player_Factory.h"
#include "objects/Player.h"
#include "Input_Handler.h"
#include "world_helper/Room_Factory.h"


using namespace std;

int main() {
    srand(time(0));
    auto selection{Menu_Item::in_menu};
    Player_Factory player_factory{};
    do {
        // *** MAIN MENU ***
        
        selection = Main_Menu::select_menu_item();
        if (selection != Menu_Item::quit) {
            Input_Handler input_handler {};
            auto player = player_factory.create_default_player();
            // Player player{};
            if (selection == Menu_Item::auto_generate) {
                player_factory.auto_generate_abilities(player);
            }
            else if (selection == Menu_Item::generate) {
                Main_Menu::display_config_help();
                player.set_state(Player_State::generate);
                do {
                    input_handler.command_loop(player);
                }
                while (player.get_state() == Player_State::generate);
            }
            
            if (player.get_state() == Player_State::playing) {

                // *** GAME INIT ***
                Room_Factory room_factory{};
                room_factory.generate_rooms();
                player.set_current_room(room_factory.get_start_room());
                // player.set_state(Player_State::playing);
                
                cout << player.get_current_room()->get_full_desc() << endl;
                
                // *** MAIN GAME LOOP ***
                do {
                    input_handler.command_loop(player);
                }
                while (player.get_state() == Player_State::playing);
            }
        }
    }
    while (selection != Menu_Item::quit);
    return 0;
}

