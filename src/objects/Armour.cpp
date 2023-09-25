#include "Armour.h"

using namespace std;

Armour::Armour(string key_name, string title, string desc, int ac) 
    : Item{key_name, title, desc},
      m_ac{ac}
{}

