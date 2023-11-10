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
    bool shutdown = false;

    do {
        Player_Factory player_factory{};
        auto player = player_factory.create_default_player();  

        // *** MAIN MENU ***    
        shutdown = Main_Menu::launch(player);
        
        if (player.get_state() == Player_State::playing) {

            // *** GAME INIT ***
            Room_Factory room_factory{};
            room_factory.generate_rooms();
            player.set_current_room(room_factory.get_start_room());
            cout << player.get_current_room()->get_full_desc() << endl;
            
            // *** MAIN GAME LOOP ***
            do {
                Input_Handler::handle_command(player);
            }
            while (player.get_state() == Player_State::playing);
        }
    }
    while (!shutdown);
    return 0;
}

