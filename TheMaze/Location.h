#pragma once
class Location
{
private:
	int _row;
	int _col;
	Location();
public:
	static Location NoLocation;

	Location(int row, int col);
	int getRow() const;
	int getCol() const;

	bool operator ==(const Location& other);
	bool operator !=(const Location& other);
};

