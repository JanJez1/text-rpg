#include "Creature_Factory.h"

using namespace std;

unique_ptr<Creature> Creature_Factory::create(string str) {

    // ANIMALS - NO INVENTORY
    if (str == "rat") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 5}
        };    
        return make_unique<Animal>(
            "rat",
            "a small rat",
            "A small rat.",
            params
        );
    }

    // ANIMALS WITH INVENTORY
    if (str == "bat") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 5}
        };    
        auto creature = make_unique<Animal>(
            "bat",
            "a grey bat",
            "Rather small but nimble flying creature.",
            params
        );
        return move(creature);
    }
    
    // HUMANOIDS
    if (str == "green_orc") {
        std::map<Param_Type, short> params {
            {Param_Type::ac, 5}
        };    
        auto creature = make_unique<Humanoid>(
            "orc",
            "a green orc",
            "Sturdy ugly humanoid creature with green skin.",
            params
        );
        creature->add_item("rusty_dagger", true);
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


