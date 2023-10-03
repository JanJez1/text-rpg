#include "Room.h"

using namespace std;

Room::Room(string title, string desc)
    : m_title{title},
      m_desc{desc},
      m_exits{},
      m_items{}
{}

string Room::get_full_desc() {
    string full_desc  = "\n" +
        to_upper(m_title) + "\n" +
        to_upper(m_desc) + "\n";
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
    string exits_string{"Exits: "};
    if(m_exits.size()==0)
        exits_string = "none";
    else
        for(const auto& [key, v]: m_exits)
            exits_string += exit_to_string(key) += " "; // ToDO: change to coma separated list
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