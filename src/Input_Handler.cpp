#include "Input_Handler.h"

using namespace std;

Input_Handler::Input_Handler(string input)
: tokens{}
{
}

// split string into substrings and save to 'vector<string> tokens'
// first substring is considered as verb (command)
// the rest of substrings (if any) are params
void Input_Handler::parse_input(std::string input_line) {

    tokens.clear();
    
    if (input_line.size() < 1) 
        return;
        
    size_t start = 0;
    size_t end = input_line.find(' ');
    string token = "";
    
    while (end != string::npos) {
        token = input_line.substr(start, end - start);
        if (token != "")
            tokens.push_back(token);
        start = end + 1;
        end = input_line.find(' ', start);
    }
    token = input_line.substr(start);
    if (token != "")
        tokens.push_back(token); 
}

