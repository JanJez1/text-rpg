#include "Object.h"

using namespace std;

Object::Object(string key_name, string title, string desc, Object_Type object_type)
    : m_key_name{key_name},
      m_title{title},
      m_desc{desc},
      m_object_type{object_type}
{}

bool Object::is_wearable() {
  if (
    m_object_type == Object_Type::armour ||
    m_object_type == Object_Type::boots ||
    m_object_type == Object_Type::gauntlets ||
    m_object_type == Object_Type::helmet) {
      return true;
  }
  else
    return false;
}

bool Object::is_holdable() {
  if (
    m_object_type == Object_Type::shield ||
    m_object_type == Object_Type::weapon ) {
      return true;
  }
  else
    return false;
}