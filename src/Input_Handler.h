#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <vector>
#include <string>
#include "objects/Player.h"
#include "Commands.h"

class Input_Handler
{
private:
    static std::vector<std::string> parse_input(std::string);
    static std::vector<std::string> handle_input(Player&);
   
public:
    static void handle_command(Player&);
    static void handle_menu_command(Player&);
};

#endif // INPUT_HANDLER_H
