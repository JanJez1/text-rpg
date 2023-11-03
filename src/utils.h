#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstdlib>

#include "Object.h"
#include "defs.h"
#include "objects/Item.h"

enum Exit {north, east, south, west, invalid};

std::string to_upper(std::string);
std::string remove_article(std::string);

Exit get_opposite_exit(Exit);
std::string exit_to_string(Exit);
Exit string_to_exit(std::string);

std::string object_type_to_string(Object_Type);

int exp_to_advance(int lvl);

template <typename T>
typename std::vector<std::shared_ptr<T>>::iterator find_elem(std::string str, std::vector<std::shared_ptr<T>>& vec) {
    return std::find_if(vec.begin(), vec.end(),
        [&](std::shared_ptr<T> & obj){ return obj->get_key_name() == str;});
}

template <typename T>
typename std::vector<std::unique_ptr<T>>::iterator find_elem(std::string str, std::vector<std::unique_ptr<T>>& vec) {
    return std::find_if(vec.begin(), vec.end(),
        [&](std::unique_ptr<T> & obj){ return obj->get_key_name() == str;});
}

int random(int min, int max);
int random(int max);

#endif // UTILS_H