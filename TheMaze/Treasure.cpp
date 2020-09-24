#include "Treasure.h"

Treasure::Treasure(int value)
{
    this->_value = value;
}

int Treasure::getValue()
{
    return this->_value;
}
