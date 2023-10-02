#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "Object.h"
#include "defs.h"
#include "objects/Item.h"

enum Exit {north, east, south, west, invalid};

std::string to_upper(std::string);
Exit get_opposite_exit(Exit);
std::string exit_to_string(Exit);
Exit string_to_exit(std::string);

std::string object_type_to_string(Object_Type);

std::vector<std::unique_ptr<Object>>::iterator find_elem(std::string str, std::vector<std::unique_ptr<Object>>& vec);

#endif // UTILS_H