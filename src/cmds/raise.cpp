#include "Raise.h"

std::string Raise::action(std::vector<std::string> params, Player& player) {
    if (params.size() == 0)
        return "You have to specify which ability to raise.";
    if (params.size() > 2)
        return "Too many parameters.";
    
    // which ability to raise
    std::string ability_string = get_full_ability_string(params.at(0));
    auto ability_to_raise = str_to_param_type(ability_string);   
    if (ability_to_raise == Param_Type::invalid)
        return "Invalid ability name.";

    // how much to raise
    int amount = 1;     // if amount not specified, raise by 1;
    if (params.size() == 2) {
        try {
            amount = std::stoi(params.at(1));
        }
        catch (std::invalid_argument const& ex) {
            return "Invalid amount of ability points.";
        }
        if (amount < 1)
            return "Invalid amount of ability points.";
    }
    
    int free_ability_points = player.get_base_param(Param_Type::free_ability_points);
    if (amount > free_ability_points)
        return "You don't have enough free ability points.";
    
    // max value ability check
    if ( (amount + player.get_base_param(ability_to_raise)) > get_ability_max(player.get_level()) )
        return "You can't raise " + ability_string + " above " + 
            std::to_string(get_ability_max(player.get_level())) + ".";
    
    player.raise_base_param(ability_to_raise, amount);
    player.raise_base_param(Param_Type::free_ability_points, -amount);

    return "You raised " + ability_string + " by " + std::to_string(amount) + " to " 
        + std::to_string(player.get_base_param(ability_to_raise)) + ".";
}

int Raise::get_ability_max(int level) {
    if ( level < 2)
        return 15;
    if ( level < 6 )
        return 18;
    return 20;
}