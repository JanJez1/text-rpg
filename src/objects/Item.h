#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

#include "../defs.h"
#include "../Object.h"

class Item: public Object
{
private:
    std::map<Param_Type, short> item_params;
    bool equipped;

public:
    Item(std::string,
        std::string title,
        std::string desc,
        Object_Type object_type = Object_Type::item,
        std::map<Param_Type, short> item_params = std::map<Param_Type, short>{}
    );
    virtual ~Item() = default;

    bool is_equipped() { return equipped; }
    virtual void set_equipped(bool eq) { equipped = eq; }
    bool is_wearable();
    bool is_holdable();
    const std::map<Param_Type, short>& get_item_params() { return item_params; }
};

#endif // ITEM_H