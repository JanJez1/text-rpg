#include "../world_helper/Creature_Factory.h"

using namespace std;


unique_ptr<Creature> Creature_Factory::create(string title) {

    // ANIMALS 

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
    if (title == "an old goblin") {
        auto creature = make_unique<Humanoid>(
            "goblin",
            title,
            "Decrepit ugly humanoid creature with green skin.",
            std::map<Param_Type, short> {
                {Param_Type::str, 10},
                {Param_Type::dex, 9},
                {Param_Type::con, 15},
                {Param_Type::attack, 2},
                {Param_Type::max_hp, 15},
                {Param_Type::ac, 0}
            } 
        );
            creature->add_item("a rusty dagger", true);
            creature->add_item("dirty rags", true);
        return move(creature);
    }

        if (title == "a sturdy goblin") {
        auto creature = make_unique<Humanoid>(
            "goblin",
            title,
            "Sturdy ugly humanoid creature with green skin.",
            std::map<Param_Type, short> {
                {Param_Type::str, 15},
                {Param_Type::dex, 9},
                {Param_Type::con, 15},
                {Param_Type::attack, 2},
                {Param_Type::max_hp, 20},
                {Param_Type::ac, 0}
            } 
        );
            creature->add_item("a rusty dagger", true);
            creature->add_item("a leather vest", true);
            creature->add_item("a healing potion");
            creature->add_item("a massive iron key");
        return move(creature);
    }


    // DEFAULT CREATURE
    std::map<Param_Type, short> params {
        {Param_Type::ac, 5},
        {Param_Type::max_hp, 5}
    }; 
    return make_unique<Animal>("blob", "an unidentified blob", "useless piece of blob", params);
}


