#include "Profile.h"

std::string Profile::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "You can check yourself only.";
    return player.get_profile();
}
