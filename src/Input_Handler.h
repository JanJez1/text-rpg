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
    std::vector<std::string> tokens{};
    std::string response{};
    std::string input_line{};
    Commands commands{};
   
public:
    void parse_input(std::string);
    void command_loop(Player&);
};

#endif // INPUT_HANDLER_H
