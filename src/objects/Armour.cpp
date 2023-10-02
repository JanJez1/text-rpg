#include "Armour.h"

using namespace std;

Armour::Armour(string key_name, string title, string desc, int ac, Object_Type object_type) 
    : Item{key_name, title, desc, object_type},
      m_ac{ac}
{}

