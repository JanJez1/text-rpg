#include "../world_helper/Creature_Factory.h"

using namespace std;


unique_ptr<Creature> Creature_Factory::create(string title) {

    // ANIMALS 
    if (title == "a small rat") {  
        auto creature = make_unique<Animal>(
            "rat",
            title,
            "A small rat.",
            std::map<Param_Type, short> {
                {Param_Type::ac, 5}
            } 
        );
        return move(creature);
    }

    if (title == "a grey bat") {
        auto creature = make_unique<Animal>(
            "bat",
            title,
            "Rather small but nimble flying creature.",
            std::map<Param_Type, short> {
                {Param_Type::ac, 5}
            } 
        );
        creature->set_position("flying");
        return move(creature);
    }

   
    
    // HUMANOIDS
    if (title == "a green orc") {
        auto creature = make_unique<Humanoid>(
            "orc",
            title,
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
            creature->add_item("a rusty dagger", true);
            creature->add_item("a leather cap", true);
            creature->add_item("a tiny iron key"); 
        return move(creature);
    }


    // DEFAULT CREATURE
    std::map<Param_Type, short> params {
        {Param_Type::ac, 5},
        {Param_Type::max_hp, 5}
    }; 
    return make_unique<Animal>("blob", "an unidentified blob", "useless piece of blob", params);
}


