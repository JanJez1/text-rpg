#include "Inventory.h"

std::string Inventory::action(std::vector<std::string> params, Player& player) {

    if (params.size() > 0) {
            return "You can inspect only your inventory.";
    }
    
    auto& inv = player.get_inv();
    if(inv.size() == 0) {
        return "You carry nothing.";
    }

    std::string output = "\nYou carry:\n";
    for(const auto& item: inv) {
        output += "  " + item->get_title() + "\n";
    }

    return output;
}
