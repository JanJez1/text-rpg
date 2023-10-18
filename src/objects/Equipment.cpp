#include "Equipment.h"

using namespace std;

Equipment::Equipment(string key_name, string title, string desc, Object_Type object_type, map<Param_Type, short> item_params_)
    : Item{key_name, title, desc, object_type, item_params_},
    equipped{false}
 {}

bool Equipment::is_wearable() {
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

bool Equipment::is_holdable() {
  if (
    get_object_type() == Object_Type::shield ||
    get_object_type() == Object_Type::weapon ) {
      return true;
  }
  else
    return false;
}