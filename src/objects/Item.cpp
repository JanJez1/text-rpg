#include "Item.h"

using namespace std;

Item::Item(string key_name, string title, string desc, Object_Type object_type)
    : Object{key_name, title, desc, object_type},
    equipped{false}
{}