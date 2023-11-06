#include "Quit.h"

std::string Quit::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "No paramaters allowed.";
    player.set_state(Player_State::quit);
    return "Thanks for playing!";
}
