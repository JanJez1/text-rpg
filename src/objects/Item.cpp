#include "Item.h"

using namespace std;

Item::Item(string key_name, string title, string desc, Object_Type object_type)
    : Object{key_name, title, desc, object_type},
    equipped{false}
{}

bool Item::is_wearable() {
  if (
    get_object_type() == Object_Type::armour ||
    get_object_type() == Object_Type::boots ||
    get_object_type() == Object_Type::gauntlets ||
    get_object_type() == Object_Type::helmet) {
      return true;
  }
  else
    return false;
}

bool Item::is_holdable() {
  if (
    get_object_type() == Object_Type::shield ||
    get_object_type() == Object_Type::weapon ) {
      return true;
  }
  else
    return false;
}