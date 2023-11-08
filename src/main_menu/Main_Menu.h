#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>
#include <iostream>

#include "../defs.h"


class Main_Menu
{
private:
    /* data */
public:
    static Menu_Item select_menu_item();
    static void display_config_help();
    static std::string get_config_help();
};



#endif // MAIN_MENU_H