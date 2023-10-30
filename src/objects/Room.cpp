#include "Room.h"

using namespace std;

Room::Room(string title, string desc, bool resetable_)
    : m_title{title},
      m_desc{desc},
      m_details{},
      m_exits{},
      m_doors{},
      m_items{},
      m_creatures{},
      resetable{resetable_},
      m_creatures_backup{},
      last_kill_time{0}
{}

string Room::get_full_desc() {
    return Room_Desc::get_full_desc(m_title, m_desc, m_creatures, m_items, m_exits, m_doors);
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

void Room::add_door(Exit exit, shared_ptr<Special_Object> door) {
    m_doors.insert({exit, door.get()});
    m_items.push_back(door);
}

Special_Object* Room::get_door(Exit exit) {
    if (m_doors.size() == 0)
        return nullptr;
    for(auto [ex, p_door]: m_doors) {
        if(ex == exit)
            return p_door;
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

void Room::add_special_item(unique_ptr<Special_Object> special_item) {
    m_items.push_back(move(special_item));
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