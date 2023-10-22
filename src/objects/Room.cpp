#include "Room.h"

using namespace std;

Room::Room(string title, string desc, bool resetable_)
    : m_title{title},
      m_desc{desc},
      m_details{},
      m_exits{},
      m_items{},
      m_creatures{},
      resetable{resetable_},
      m_creatures_backup{},
      last_kill_time{0}
{}


string Room::get_full_desc() {
    
    string full_desc  = "\n" +
        to_upper(m_title) + "\n" +
        to_upper(m_desc) + "\n";
  
    // CREATURES IN ROOM
    // one creature per line
    if (m_creatures.size() > 0 ) {
        for(const auto &creature: m_creatures)
            full_desc += to_upper(creature->get_title() + " is " + creature->get_position() + " here.\n");
    }
    
    // ITEMS IN ROOM 
    // first exclude not visible (special) items from list of items lying on the ground
    vector<Item*> visible_items;
    for (const auto &item: m_items) {
        if ( item->is_visible() )
            visible_items.push_back(item.get());
    }

    if (visible_items.size() > 0 ) {
        string items_string{visible_items.at(0)->get_title()};
        if(visible_items.size() == 1)
            items_string += " is here.\n";
        else {
            if(visible_items.size()>2) {
                for(size_t i{1}; i <= visible_items.size()-2; i++)
                    items_string += ", " + visible_items.at(i)->get_title();
            }
            items_string += " and " + visible_items.back()->get_title() +" are here.\n";
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

string Room::find_detail(string key) {
    auto itr = m_details.find(key);
    if (itr != m_details.end()) {
        return itr->second;
    }
    return "";
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

void Room::event_enter() {
    if (resetable && m_creatures.size() == 0 && m_creatures_backup.size() > 0 && (last_kill_time + 20) < time(0)) {
        m_creatures.clear();
        for(const string &name: m_creatures_backup) {
            // cannot simply call add_creature as it would increase m_creatures_backup
            m_creatures.push_back(move(Creature_Factory::create(name)));
        }
    }
}

void Room::add_item(std::string name) {
    m_items.push_back(move(Item_Factory::create(name)));
}

Item* Room::find_item(std::string name) {
    auto iter = find_elem(name, m_items);
    if (iter == m_items.end())
        return nullptr;
    return (*iter).get();
}

void Room::add_special_item(string name, Room* target_room) {
    m_items.push_back(move(Special_Object_Factory::create(name, this, target_room)));
}

void Room::add_creature(std::string name) {
    if(resetable) {
        m_creatures_backup.push_back(name);
    }
    m_creatures.push_back(move(Creature_Factory::create(name)));
}

Creature* Room::find_creature(std::string name) {
    auto iter = find_elem(name, m_creatures);
    if (iter == m_creatures.end())
        return nullptr;
    return (*iter).get();
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
    last_kill_time = time(0);
}