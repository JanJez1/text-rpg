#include "Main_Menu.h"

using namespace std;

void print_main_menu() {
    cout << endl;
    cout << "MAIN MENU" << endl;
    cout << "'a' - auto generate hero and Play" << endl;
    cout << "'g' - Generate hero" << endl;
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
        if (input == "a" || input == "A")
            selection = Menu_Item::auto_generate;
        else if (input == "g" || input == "G")
            selection = Menu_Item::generate;
        else if (input == "q" || input == "Q")
            selection = Menu_Item::quit;
        else
            cout << "Invalid selection."  << endl;
    }
    while (selection == Menu_Item::in_menu);
    return selection;
}