#include "Main_Menu.h"

using namespace std;

bool /*shutdown*/ Main_Menu::launch(Player& player) {
    auto selection = select_menu_item();

    if (selection == Menu_Item::shutdown) {
        return true;
    }

    else if (selection == Menu_Item::player_config_auto) {
        Player_Factory player_factory;
        player_factory.auto_generate_abilities(player);
        player.set_state(Player_State::playing);
    }
    
    else if (selection == Menu_Item::player_config_manual) {
        Main_Menu::display_config_help();
        player.set_state(Player_State::config);
        do {
            Input_Handler::handle_menu_command(player);
        }
        while (player.get_state() == Player_State::config);
    }
    return false;
}

void print_main_menu() {
    cout << endl;
    cout << "MAIN MENU" << endl;
    cout << "'p' - Play (with random hero)" << endl;
    cout << "'c' - Customize hero" << endl;
    cout << "'q' - Quit" << endl;
    cout << "Choose 'a', 'g' or 'q'" << endl;
    cout << "> ";
}

Menu_Item Main_Menu::select_menu_item() {
    auto selection{Menu_Item::in_menu};
    string input;
    do {
        print_main_menu();
        getline (cin, input);
        if (input == "p" || input == "P")
            selection = Menu_Item::player_config_auto;
        else if (input == "c" || input == "C")
            selection = Menu_Item::player_config_manual;
        else if (input == "q" || input == "Q")
            selection = Menu_Item::shutdown;
        else
            cout << "Invalid selection."  << endl;
    }
    while (selection == Menu_Item::in_menu);
    return selection;
}

string Main_Menu::get_config_help() {
    std::string config_help = 
        "The hero is characterized by three abilities: strength, dexterity and constitution.\n"
        "Strength increases attack.\n"
        "Dexterity improves defence.\n"
        "Constitution increases maximal health points.\n\n"
        "Default values are 10 for each ability.\n"
        "You have 7 ability points to distribute among abilities.\n"
        "Maximal ability value is 15, from level 2 it is 18.\n\n"
        "Available commands:\n"
        "- help     displays this page\n"
        "- play     you enter the game (with current abilities)\n"
        "- profile  displays current ability values\n"
        "- raise    raise specific ability value ('raise strength', 'raise str 3')\n"
        "- reset    resets ability values to default values (10)\n"
        "- quit     back to main menu\n";
    return config_help;
}

void Main_Menu::display_config_help() {
    cout << Main_Menu::get_config_help();
}