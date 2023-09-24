#ifndef UTILS_H
#define UTILS_H

enum Exit {north, east, south, west, invalid};

std::string to_upper(std::string);
Exit get_opposite_exit(Exit);
std::string exit_to_string(Exit);
Exit string_to_exit(std::string);

#endif // UTILS_H