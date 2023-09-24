#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>
#include <string>

class Input_Handler
{
private:
    std::vector<std::string> tokens;
    
public:
    Input_Handler(std::string input="");

    void parse_input(std::string);
    std::vector<std::string> get_tokens() {return tokens; }
    std::string get_verb() {return tokens.at(0);}
};

#endif // INPUT_HANDLER_H
