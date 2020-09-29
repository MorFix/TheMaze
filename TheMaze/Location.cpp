#include "Location.h"

Location::Location(int row, int col)
{
    this->_row = row;
    this->_col = col;
}

int Location::getRow()
{
    return this->_row;
}

int Location::getCol()
{
    return this->_col;
}
