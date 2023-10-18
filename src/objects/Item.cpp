#include "Item.h"

using namespace std;

Item::Item(string key_name, string title, string desc, Object_Type object_type, map<Param_Type, short> item_params_)
    : Object{key_name, title, desc, object_type},
    item_params{item_params_}
{}
