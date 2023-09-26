#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc)
    : Object{key_name, title, desc},
      m_inv{}
{}

void Creature::add_item_to_inv(std::unique_ptr<Object> item) {
    m_inv.push_back(move(item));
}

Object* Creature::find_item_in_inv(std::string str) {
    return find_obj_in_vector(str, m_inv);
}

unique_ptr<Object> Creature::move_item_from_inv(string str) {
    return move_obj_from_vector(str, m_inv);
}