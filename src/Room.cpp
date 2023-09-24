#include "Room.h"

using namespace std;

Room::Room(string title_, string desc_)
: title{title_}, desc{desc_}, exits{}, items{}
{
}

string Room::get_full_desc() {
    string full_desc  = "\n" +
        to_upper(title) + "\n" +
        to_upper(desc) + "\n";
    if (items.size() > 0 ) {
        string items_string{items.at(0)->get_title()};
        if(items.size() == 1)
            items_string += " is lying here.\n";
        else {
            if(items.size()>2) {
                for(size_t i{1}; i <= items.size()-1; i++)
                    items_string += ", " + items.at(i)->get_title();
            }
            items_string += "and " + items.back()->get_title() +" are lying here.\n";
        }
        full_desc += to_upper(items_string);
    }
    string exits_string{"Exits: "};
    if(exits.size()==0)
        exits_string = "none";
    else
        for(const auto& [key, v]: exits)
            exits_string += exit_to_string(key) += " "; // ToDO: change to coma separated list
    full_desc += exits_string;
    return full_desc;
}

void Room::add_exit(Exit exit, Room *p_room) {
    exits.insert({exit, p_room});
}

Room* Room::get_exit(Exit exit) {
    if (exits.size() == 0)
        return nullptr;
    for(auto [ex, p_room]: exits) {
        if(ex == exit)
            return p_room;
    }
    return nullptr;
}

Item* Room::find_item(string target_string) {
    if(items.size() > 0) {
        for(auto const &item: items) {
            if (item->get_key_name() == target_string) 
                return item.get();
        }
    }
    return nullptr;
}