#include "Input_Handler.h"

// split string into substrings and save to 'vector<string> tokens'
// first substring is considered as verb (command)
// the rest of substrings (if any) are params
std::vector<std::string> Input_Handler::parse_input(std::string input_line) {

    std::vector<std::string> tokens{};

    if (input_line.size() < 1) 
        return tokens;
        
    size_t start = 0;
    size_t end = input_line.find(' ');
    std::string token = "";

    while (end != std::string::npos) {
        token = input_line.substr(start, end - start);
        if (token != "")
            tokens.push_back(token);
        start = end + 1;
        end = input_line.find(' ', start);
    }
    token = input_line.substr(start);
    if (token != "")
        tokens.push_back(token);
    return tokens;
}

std::vector<std::string> Input_Handler::handle_input(Player& player) {
    std::cout << "> ";
    std::string input_line;
    getline (std::cin, input_line);
    return parse_input(input_line);
}

void Input_Handler::handle_command(Player& player) {
    auto tokens = handle_input(player);
    std::cout << Commands::execute_command(tokens, player) << std::endl;
}

void Input_Handler::handle_menu_command(Player& player) {
    auto tokens = handle_input(player);
    std::cout << Commands::execute_menu_command(tokens, player) << std::endl;
}

