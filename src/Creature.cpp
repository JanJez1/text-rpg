#include "Creature.h"

using namespace std;

Creature::Creature(string key_name, string title, string desc)
    : Object{key_name, title, desc},
      m_inv{}
{
}


void Creature::add_item(std::unique_ptr<Object> item) {
    m_inv.push_back(move(item));
}

// iter to items in room
string Creature::event_pick_item(vector<unique_ptr<Object>>::iterator iter) {
    string response = "You've picked up " + (*iter)->get_title() + "."; 
    if (get_current_room() != nullptr) { 
        m_inv.push_back(move(*iter));
        get_current_room()->get_items().erase(iter);
    }
    return response;
}

// iter to inventory
string Creature::event_drop_item(vector<unique_ptr<Object>>::iterator iter) {
    string response = "";
    if ((*iter)->is_equipped())
        response = event_remove_item(iter) + "\n";
    
    response += "You've dropped " + (*iter)->get_title() + "."; 
    // ToDo: add try / catch to be sure
    if (get_current_room() != nullptr) { 
        get_current_room()->add_item(move(*iter));
        m_inv.erase(iter);
    }

    return response;
}

std::string Creature::event_wear_item(vector<unique_ptr<Object>>::iterator iter) {
    // if sth already equipped on the same body part
    auto worn = find_if(m_inv.begin(), m_inv.end(),
        [&](unique_ptr<Object> & obj){
        return (obj->is_equipped() && obj->get_object_type() == (*iter)->get_object_type());
    });
    string response = "";
    if(worn != m_inv.end()) {
        response = event_remove_item(worn) + "\n";
    }

    (*iter)->set_equipped(true);
    return response += "You've worn " + (*iter)->get_title() + ".";
}

std::string Creature::event_remove_item(vector<unique_ptr<Object>>::iterator iter) {
    (*iter)->set_equipped(false);
    return "You've removed " + (*iter)->get_title() + ".";
}
