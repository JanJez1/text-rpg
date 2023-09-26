#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "Object.h"
#include "objects/Item.h"

enum Exit {north, east, south, west, invalid};

std::string to_upper(std::string);
Exit get_opposite_exit(Exit);
std::string exit_to_string(Exit);
Exit string_to_exit(std::string);
std::unique_ptr<Object> move_obj_from_vector(std::string, std::vector<std::unique_ptr<Object>>&);
Object* find_obj_in_vector(std::string, std::vector<std::unique_ptr<Object>>&);


#endif // UTILS_H