#include "../world_helper/Creature_Factory.h"

using namespace std;


unique_ptr<Creature> Creature_Factory::create(string title) {

    // ANIMALS 

    if (title == "a grey bat") {
        auto creature = make_unique<Animal>(
            "bat",
            title,
            "This is a nimble flying creature with wingspan slightly above two feet.",
            std::map<Param_Type, short> {
                {Param_Type::str, 2},
                {Param_Type::dex, 16},
                {Param_Type::con, 11},
                {Param_Type::ac, 8},
                {Param_Type::attack, 0},
                {Param_Type::min_damage, 1},
                {Param_Type::max_damage, 1},
                {Param_Type::max_hp, 5},
                {Param_Type::exp_rating, 50}
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
                {Param_Type::str, 6},
                {Param_Type::dex, 10},
                {Param_Type::con, 10},
                {Param_Type::ac, 10},
                {Param_Type::max_hp, 10},
                {Param_Type::exp_rating, 20}
             } 
        );
            creature->add_item("a rusty dagger", true);
            creature->add_item("a dirty tunic", true);
        return move(creature);
    }

        if (title == "a sturdy goblin") {
        auto creature = make_unique<Humanoid>(
            "goblin",
            title,
            "Sturdy ugly humanoid creature with green skin.",
            std::map<Param_Type, short> {
                {Param_Type::str, 12},
                {Param_Type::dex, 12},
                {Param_Type::con, 15},
                {Param_Type::ac, 10},
                {Param_Type::max_hp, 20},
                {Param_Type::exp_rating, 100}
            } 
        );
            creature->add_item("a rusty dagger", true);
            creature->add_item("a leather vest", true);
            creature->add_item("a massive iron key");
        return move(creature);
    }


    // DEFAULT CREATURE
    std::map<Param_Type, short> params {}; 
    return make_unique<Animal>("error", "error", "'" + title + "' is not among available creatures. Typo, perhaps?", params);
}


