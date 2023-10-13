#include "Creature_Factory.h"

using namespace std;


unique_ptr<Creature> Creature_Factory::create(string str) {

    // ANIMALS 
    if (str == "rat") {  
        auto creature = make_unique<Animal>(
            "rat",
            "a small rat",
            "A small rat.",
            std::map<Param_Type, short> {
                {Param_Type::ac, 5}
            } 
        );
        return move(creature);
    }

    if (str == "bat") {
        auto creature = make_unique<Animal>(
            "bat",
            "a grey bat",
            "Rather small but nimble flying creature.",
            std::map<Param_Type, short> {
                {Param_Type::ac, 5}
            } 
        );
        return move(creature);
    }

   
    
    // HUMANOIDS
    if (str == "green_orc") {
        auto creature = make_unique<Humanoid>(
            "orc",
            "a green orc",
            "Sturdy ugly humanoid creature with green skin.",
            std::map<Param_Type, short> {
                {Param_Type::str, 15},
                {Param_Type::dex, 9},
                {Param_Type::con, 15},
                {Param_Type::attack, 2},
                {Param_Type::max_hp, random(15, 20)},
                {Param_Type::ac, 0}
            } 
        );
            creature->add_item("rusty_dagger", true);
            creature->add_item("leather_cap", true);
            creature->add_item("key"); 
        return move(creature);
    }


    // DEFAULT CREATURE
    std::map<Param_Type, short> params {
        {Param_Type::ac, 5},
        {Param_Type::max_hp, 5}
    }; 
    return make_unique<Animal>("blob", "an unidentified blob", "useless piece of blob", params);
}


