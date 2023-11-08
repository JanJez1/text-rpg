#include "Commands.h"

using namespace std;

Commands::Commands()
    : commands{},
      menu_commands{}
{
    commands.insert({"drink", std::make_unique<Drink>()});
    commands.insert({"drop", std::make_unique<Drop>()});
    commands.insert({"get", std::make_unique<Get>()});
    commands.insert({"go", std::make_unique<Go>()});
    commands.insert({"hit", std::make_unique<Hit>()});
    commands.insert({"attack", std::make_unique<Hit>()});
    commands.insert({"kill", std::make_unique<Hit>()});
    commands.insert({"hold", std::make_unique<Hold>()});
    commands.insert({"inventory", std::make_unique<Inventory>()});
    commands.insert({"inv", std::make_unique<Inventory>()});
    commands.insert({"i", std::make_unique<Inventory>()});
    commands.insert({"look", std::make_unique<Look>()});
    commands.insert({"l", std::make_unique<Look>()});
    commands.insert({"profile", std::make_unique<Profile>()});
    commands.insert({"prof", std::make_unique<Profile>()});
    commands.insert({"p", std::make_unique<Profile>()});
    commands.insert({"quit", std::make_unique<Quit>()});
    commands.insert({"q", std::make_unique<Quit>()});
    commands.insert({"raise", std::make_unique<Raise>()});
    commands.insert({"remove", std::make_unique<Remove>()});
    commands.insert({"unlock", std::make_unique<Unlock>()});
    commands.insert({"wear", std::make_unique<Wear>()});

    menu_commands.insert({"help", std::make_unique<Menu_Help>()});
    menu_commands.insert({"h", std::make_unique<Menu_Help>()});
    menu_commands.insert({"play", std::make_unique<Menu_Play>()});
    menu_commands.insert({"profile", std::make_unique<Menu_Profile>()});
    menu_commands.insert({"prof", std::make_unique<Menu_Profile>()});
    menu_commands.insert({"raise", std::make_unique<Raise>()});
    menu_commands.insert({"reset", std::make_unique<Menu_Reset>()});
    menu_commands.insert({"quit", std::make_unique<Menu_Quit>()});
    menu_commands.insert({"q", std::make_unique<Menu_Quit>()});
}


string Commands::execute_command(vector<string> tokens, Player& player) {
    
    if (tokens.size() < 1)
        return "No command given.";
    apply_go_aliases(tokens); //  transfers 'n' to 'go north'
    string verb = tokens.at(0);
    tokens.erase(tokens.begin()); // the first token is verb, after erasing it, only params remain in tokens
    
    if (player.get_state() == Player_State::playing) {
        if (commands.find(verb) != commands.end() )
            return commands.at(verb)->action(tokens, player);
        else
            return "Command not recognized.";
    }

    else if (player.get_state() == Player_State::generate) {
        if (menu_commands.find(verb) != menu_commands.end() )
            return menu_commands.at(verb)->action(tokens, player);
        else
            return "Command not recognized.\nAvailable commands: 'play', 'profile', 'raise', 'reset', 'quit'.";
    }
    return "Some mess in player state.";    
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
