#include "utils.h"

std::string to_upper(std::string str) {
    str[0] = std::toupper(str[0]);
    return str;
}

Exit get_opposite_exit(Exit ex) {
    switch(ex) {
        case north: return south;
        case south: return north;
        case east: return west;
        case west: return east;
        default: return invalid;
    }
}

std::string exit_to_string(Exit ex) {
    switch(ex) {
        case north: return "north";
        case south: return "south";
        case east: return "east";
        case west: return "west";
        default: return "invalid";
    }
}

Exit string_to_exit(std::string ex) {
    if (ex == "north" || ex =="n")
        return north;
    if (ex == "east" || ex =="e")
        return east;
    if (ex == "south" || ex =="s")
        return south;
    if (ex == "west" || ex =="w")
        return west;
    return invalid;
}


std::string object_type_to_string(Object_Type object_type) {
    switch(object_type) {
        case Object_Type::creature : return "creature";
        case Object_Type::item : return "item";
        case Object_Type::helmet : return "helmet";
        case Object_Type::armour : return "armour";
        case Object_Type::boots : return "boots";
        case Object_Type::gauntlets : return "gauntlets";
        case Object_Type::weapon : return "weapon";
        case Object_Type::shield : return "shield";
        default : return "undefined";
    }
}


// std::unique_ptr<Object> move_obj_from_vector(std::string str, std::vector<std::unique_ptr<Object>>& vec) {
//     auto it = (std::find_if(vec.begin(), vec.end(),
//         [&](std::unique_ptr<Object> & obj){ return obj->get_key_name() == str;}));
//     if (it != vec.end()) {
//         auto temp = std::move(*it);
//         vec.erase(it);
//         return temp;
//     }
//     return nullptr;   
// }

// Object* find_obj_in_vector(std::string str, std::vector<std::unique_ptr<Object>>& vec) {
//     auto it = (std::find_if(vec.begin(), vec.end(),
//         [&](std::unique_ptr<Object> & obj){ return obj->get_key_name() == str;}));
//     if (it != vec.end())
//         return (*it).get();
//     return nullptr;
// }

std::vector<std::unique_ptr<Object>>::iterator find_elem(std::string str, std::vector<std::unique_ptr<Object>>& vec) {
    return std::find_if(vec.begin(), vec.end(),
        [&](std::unique_ptr<Object> & obj){ return obj->get_key_name() == str;});

}

// void helper() {
//     std::vector<std::unique_ptr<Item>> items;
//     std::unique_ptr<Item> it = std::make_unique<Item>("crown", "gold crown", "described");
//     items.push_back(move(it));
//     auto obj = find_obj_in_vector("crown", items);

// }