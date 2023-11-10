#include "Commands.h"

using namespace std;

const std::map<std::string, std::unique_ptr<Cmd_Base>> Commands::init_commands() {
    std::map<std::string, std::unique_ptr<Cmd_Base>> local_cmds;
    local_cmds["drink"] = std::make_unique<Drink>();
    local_cmds["drop"] = std::make_unique<Drop>();
    local_cmds["get"] = std::make_unique<Get>();
    local_cmds["go"] = std::make_unique<Go>();
    local_cmds["hit"] = std::make_unique<Hit>();
    local_cmds["attack"] = std::make_unique<Hit>();
    local_cmds["kill"] = std::make_unique<Hit>();
    local_cmds["hold"] = std::make_unique<Hold>();
    local_cmds["inventory"] = std::make_unique<Inventory>();
    local_cmds["inv"] = std::make_unique<Inventory>();
    local_cmds["i"] = std::make_unique<Inventory>();
    local_cmds["look"] = std::make_unique<Look>();
    local_cmds["l"] = std::make_unique<Look>();
    local_cmds["profile"] = std::make_unique<Profile>();
    local_cmds["prof"] = std::make_unique<Profile>();
    local_cmds["p"] = std::make_unique<Profile>();
    local_cmds["quit"] = std::make_unique<Quit>();
    local_cmds["q"] = std::make_unique<Quit>();
    local_cmds["raise"] = std::make_unique<Raise>();
    local_cmds["remove"] = std::make_unique<Remove>();
    local_cmds["unlock"] = std::make_unique<Unlock>();
    local_cmds["wear"] = std::make_unique<Wear>();
    return local_cmds;
};

const std::map<std::string, std::unique_ptr<Cmd_Base>> Commands::init_menu_commands() {
    std::map<std::string, std::unique_ptr<Cmd_Base>> local_cmds;
    local_cmds["help"] = std::make_unique<Menu_Help>();
    local_cmds["h"] = std::make_unique<Menu_Help>();
    local_cmds["play"] = std::make_unique<Menu_Play>();
    local_cmds["profile"] = std::make_unique<Menu_Profile>();
    local_cmds["prof"] = std::make_unique<Menu_Profile>();
    local_cmds["raise"] = std::make_unique<Raise>();
    local_cmds["reset"] = std::make_unique<Menu_Reset>();
    local_cmds["quit"] = std::make_unique<Menu_Quit>();
    local_cmds["q"] = std::make_unique<Menu_Quit>();
    return local_cmds;
}

const std::map<std::string, std::unique_ptr<Cmd_Base>> Commands::commands = init_commands();
const std::map<std::string, std::unique_ptr<Cmd_Base>> Commands::menu_commands = init_menu_commands();


string Commands::execute_menu_command(vector<string> tokens, Player& player) {
   
    if (tokens.size() < 1)
        return "No command given.";
    string verb = tokens.at(0);
    tokens.erase(tokens.begin()); // the first token is verb, after erasing it, only params remain in tokens

    if (menu_commands.find(verb) != menu_commands.end() )
        return menu_commands.at(verb)->action(tokens, player);
    else
        return "Command not recognized.\nAvailable commands: 'play', 'profile', 'raise', 'reset', 'quit'.";
}

string Commands::execute_command(vector<string> tokens, Player& player) {
   
    if (tokens.size() < 1)
        return "No command given.";
    apply_go_aliases(tokens); //  transfers 'n' to 'go north'
    string verb = tokens.at(0);
    tokens.erase(tokens.begin()); // the first token is verb, after erasing it, only params remain in tokens
    
    if (commands.find(verb) != commands.end() )
        return commands.at(verb)->action(tokens, player);
    else
        return "Command not recognized.";
}

void Commands::apply_go_aliases(vector<string> &tokens) {
    if (tokens.size() == 1) {
        if(string_to_exit(tokens.at(0)) != invalid) {
            tokens.push_back(tokens.at(0));
            tokens.at(0) = "go";
            return;
        }
    }
}
