#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Object.h"
#include "utils.h"
#include "objects/Item.h"

class Creature: public Object
{
private:
    std::vector<std::unique_ptr<Object>> m_inv;
public:
    Creature(std::string, std::string title = "unknown", std::string desc = "not described");
    void add_item_to_inv(std::unique_ptr<Object>);
    std::unique_ptr<Object> move_item_from_inv(std::string);
    Object* find_item_in_inv(std::string);
    std::vector<std::unique_ptr<Object>>& get_inv() { return m_inv; };
};

#endif // CREATURE_H