#include "Status.h"

// std::string ability_value_to_string(short value) {
//     std::string str = std::to_string(value) + " ";
//     short modif = ( value - 10 ) / 2;
//     if (modif == 0)
//         return str;
//     str += "(";
//     if (modif > 0)
//         str += "+";
//     return str += std::to_string(modif) + ")";
// }

std::string Status::action(std::vector<std::string> params, Player& player) {
    if (params.size() > 0)
        return "You can check yourself only.";
    // std::string response = "";
    // response += "Strength:      " + ability_value_to_string(player.get_str()) + "\n";
    // response += "Dexterity:     " + ability_value_to_string(player.get_dex()) + "\n";
    // response += "Constitution:  " + ability_value_to_string(player.get_con()) + "\n";
    // response += "Health points: " + std::to_string(player.get_hp()) + "/" + std::to_string(player.get_max_hp()) + "\n";
    // response += "Armour class:  " + std::to_string(player.get_ac());
    
    // return response;
    return player.display_status();
}
