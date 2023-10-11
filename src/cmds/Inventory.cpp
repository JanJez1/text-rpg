#include "Inventory.h"

//  std::string get_equipped_item_string(std::unique_ptr<Object>& item) {
//     if (item == nullptr) return "---";
//     return item->get_title();
//  }

// std::string get_equipped_string(std::map<Object_Type, std::unique_ptr<Object>>& equipped) {
//     std::string str = "You have equipped:\n";
//     for(auto& [key, val] : equipped) {
//         str += "  " + object_type_to_string(key) + ": " + get_equipped_item_string(val);
//     }
//     return str;
// }

std::string Inventory::action(std::vector<std::string> params, Player& player) {

    if (params.size() > 0) {
            return "You can inspect only your inventory.";
    }
    
    auto& inv = player.get_inv();

    if(inv.size() == 0 ) {
        return "You carry nothing.";
    }

    std::string output = "\nYou carry:\n";
    for(const auto& item: inv) {
        output += "  " + item->get_title();
        if(item->is_equipped()) {
            if(item->is_wearable())
                output += " (worn)";
            if(item->is_holdable())
                output += " (held)";
        }
        output += "\n";
    }

    return output;
}
