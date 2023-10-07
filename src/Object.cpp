#include "Object.h"

using namespace std;

Object::Object(string key_name, string title, string desc, Object_Type object_type)
    : m_key_name{key_name},
      m_title{title},
      m_desc{desc},
      m_object_type{object_type}
{}

