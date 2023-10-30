#include "Room_Desc.h"

using namespace std;


string Room_Desc::get_full_desc(
    const string &title,
    const string &desc,
    const vector<unique_ptr<Creature>> &creatures,
    const vector<shared_ptr<Item>> &items,
    const map<Exit, Room*> &exits,
    const map<Exit, Special_Object*> &doors) {
    
    string full_desc  = "\n" +
        to_upper(title) + "\n" +
        to_upper(desc) + "\n";
  
    // CREATURES IN ROOM
    // one creature per line
    if (creatures.size() > 0 ) {
        for(const auto &creature: creatures)
            full_desc += to_upper(creature->get_title() + " is " + creature->get_position() + " here.\n");
    }
    
    // ITEMS IN ROOM 
    // first exclude not visible (special) items from list of items lying on the ground
    vector<Item*> visible_items;
    for (const auto &item: items) {
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
    if(exits.size()==0)
        exits_string = "none";
    else {
        auto itr = exits.begin();
        exits_string += exit_to_string(itr->first);
        auto door_itr = doors.find(itr->first);
        if (door_itr != doors.end() && door_itr->second->get_object_state() == Object_State::locked)
            exits_string += " (x)";
        itr++;
        for(; itr != exits.end(); itr++) {
            exits_string += ", " + exit_to_string(itr->first);
            door_itr = doors.find(itr->first);
            if (door_itr != doors.end() && door_itr->second->get_object_state() == Object_State::locked)
                exits_string += " (x)";
        }
    }
    full_desc += exits_string;

    return full_desc;
}
