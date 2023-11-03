#include "utils.h"

std::string to_upper(std::string str) {
    str[0] = std::toupper(str[0]);
    return str;
}

std::string remove_article(std::string input) {
    size_t space_position = input.find(' ');
    if (space_position == std::string::npos)
        return input;
    std::string first_word = input.substr(0, space_position);
    if (first_word == "a" || first_word == "an" || first_word == "the" )
        input = input.substr(space_position + 1, input.back());
    return input;
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

int random(int min, int max) {
    // if (min < 0) 
    //     min = 0;
    // if (min > max)
    //     return min;
    return (rand() % (max - min + 1)) + min;
}

int random(int max) {
    return random(1, max);
}


int exp_to_advance(int lvl) {
    switch (lvl) {
        case 1: return 300;
        case 2: return 900;
        case 3: return 2700;
        case 4: return 6500;
        case 5: return 14000;
    }
    return 20000;
};