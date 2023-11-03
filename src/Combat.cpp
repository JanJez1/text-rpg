#include "Combat.h"

using namespace std;

int eval_damage(Creature& attacker, Creature& defender) {
    if (attacker.get_hr() <= defender.get_ac())
        return 0;
    int damage = attacker.get_dr();
    defender.alter_hp(-damage);
    return damage;
}

string perform_attack(Creature& attacker, Creature& defender){
    string defender_str = remove_article(defender.get_title());
    string attacker_str = remove_article(attacker.get_title());
    int damage = eval_damage(attacker, defender);
    if (damage == 0)
        return to_upper(attacker_str + " missed " + defender_str + ".");
    string message = to_upper(attacker_str + " hit " + defender_str + " inflicting " + std::to_string(damage) + " damage.");
    if (defender.get_hp() <= 0) {
        message += "\n" + to_upper(attacker_str + " killed " + defender_str + ".");
    }
    return message;
}


string Combat::compute_round(Player& player, Creature& creature) {
    string message = perform_attack(player, creature);
    if (creature.get_hp() <= 0)
        message += player.creature_killed(creature);
    else
        message += "\n" + perform_attack(creature, player);
    return message;
}

