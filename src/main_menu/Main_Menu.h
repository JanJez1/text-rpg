#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>
#include <iostream>

#include "../defs.h"
#include "../Input_Handler.h"
#include "../objects/Player.h"
#include "Player_Factory.h"


class Main_Menu
{
private:
    static Menu_Item select_menu_item();
public:
    static bool /*shutdown*/ launch(Player&); 

    static void display_config_help();
    static std::string get_config_help();
};



#endif // MAIN_MENU_H