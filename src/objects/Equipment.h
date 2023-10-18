#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <map>

#include "../defs.h"
#include "Item.h"

class Equipment: public Item
{
private:
    bool equipped;

public:
    Equipment(std::string,
        std::string title,
        std::string desc,
        Object_Type object_type = Object_Type::item,
        std::map<Param_Type, short> item_params = std::map<Param_Type, short>{}
    );
    virtual ~Equipment() = default;

    bool is_equipped() override { return equipped; }
    void set_equipped(bool eq) override { equipped = eq; }
    bool is_wearable() override;
    bool is_holdable() override;
};

#endif // EQUIPMENT_H