#include "Item.h"

using namespace std;

Item::Item(string key_name, string title, string desc)
    : m_key_name{key_name},
      m_title{title},
      m_desc{desc}
{}