#pragma once
class Location
{
private:
	int _row;
	int _col;
public:
	Location(int row, int col);
	int getRow();
	int getCol();
};

