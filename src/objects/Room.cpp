#include "Room.h"

using namespace std;

Room::Room(string title, string desc)
    : m_title{title},
      m_desc{desc},
      m_exits{},
      m_items{},
      m_creatures{}
{}

// string objects_in_room_to_string(const vector<unique_ptr<Object>>& objects) {
//     string objects_string{objects.at(0)->get_title()};
//     if(objects.size() > 1) {
//         if(objects.size()>2) {
//             for(size_t i{1}; i <= objects.size()-2; i++)
//                 objects_string += ", " + objects.at(i)->get_title();
//         }
//         objects_string += " and " + objects.back()->get_title();
//     }
//     return objects_string; 
// }

string Room::get_full_desc() {
    
    string full_desc  = "\n" +
        to_upper(m_title) + "\n" +
        to_upper(m_desc) + "\n";
  
    // MONSTERS IN ROOM
    if (m_creatures.size() > 0 ) {
        string items_string{m_creatures.at(0)->get_title()};
        if(m_creatures.size() == 1)
            items_string += " is standing here.\n";
        else {
            if(m_creatures.size()>2) {
                for(size_t i{1}; i <= m_creatures.size()-2; i++)
                    items_string += ", " + m_creatures.at(i)->get_title();
            }
            items_string += " and " + m_creatures.back()->get_title() +" are standing here.\n";
        }
        full_desc += to_upper(items_string);
    }
    
    // ITEMS IN ROOM 
    // -  identical to monsters in room, but no simple solution to extract repeated code
    //    Only solution I know - template with function definition in header - not good
    if (m_items.size() > 0 ) {
        string items_string{m_items.at(0)->get_title()};
        if(m_items.size() == 1)
            items_string += " is lying here.\n";
        else {
            if(m_items.size()>2) {
                for(size_t i{1}; i <= m_items.size()-2; i++)
                    items_string += ", " + m_items.at(i)->get_title();
            }
            items_string += " and " + m_items.back()->get_title() +" are lying here.\n";
        }
        full_desc += to_upper(items_string);
    }

    // EXITS:
    string exits_string{"Exits: "};
    if(m_exits.size()==0)
        exits_string = "none";
    else {
        auto itr = m_exits.begin();
        exits_string += exit_to_string(itr->first);
        itr++;
        for(; itr != m_exits.end(); itr++)
            exits_string += ", " + exit_to_string(itr->first) += " ";
    }
    full_desc += exits_string;
    
    return full_desc;
}

void Room::add_exit(Exit exit, Room *p_room) {
    m_exits.insert({exit, p_room});
}

Room* Room::get_exit(Exit exit) {
    if (m_exits.size() == 0)
        return nullptr;
    for(auto [ex, p_room]: m_exits) {
        if(ex == exit)
            return p_room;
    }
    return nullptr;
}

void Room::creature_killed(Creature& killed) {
    // move inventory of killed creature to room
    if (killed.get_inv().size() > 0) {
        for (auto iter = killed.get_inv().begin(); iter != killed.get_inv().end(); iter++) {
            (*iter)->set_equipped(false);
            add_item(std::move(*iter));
        }
    }
    // destruct killed creature
    auto iter_creature = find_elem(killed.get_key_name(), get_creatures());
    if( iter_creature != get_creatures().end() ) {
        get_creatures().erase(iter_creature);
    }
}