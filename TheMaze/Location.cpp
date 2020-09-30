#include "Location.h"

Location::Location()
{
    this->_row = -1;
    this->_col = -1;
}

Location::Location(int row, int col)
{
    this->_row = row;
    this->_col = col;
}

int Location::getRow() const
{
    return this->_row;
}

int Location::getCol() const
{
    return this->_col;
}

bool Location::operator == (const Location& other) {
    return this->getRow() == other.getRow() && this->getCol() == other.getCol();
}

bool Location::operator != (const Location& other) {
    return !((*this) == other);
}

Location Location::NoLocation = Location();