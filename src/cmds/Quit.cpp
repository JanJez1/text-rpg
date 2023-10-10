#include "Quit.h"



std::string Quit::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No paramaters allowed.";
    // ToDo: save player
    player.quit_game();
    return "Thanks for playing!";
}