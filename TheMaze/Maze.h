#pragma once
#include <iostream>
#include "Room.h"

using namespace std;

class Maze {
private:
	Room*** _rooms;
	int _rows;
	int _cols;

	friend ostream& operator<<(ostream& out, const Maze& maze);
	bool isExternal(Room* room);
	Room** getExternalRooms();
	Room** getConnectedExternalRooms(Room* room);
public:
	Maze(int rows, int cols);
	Maze(const Maze& other);
	void setData(int rows, int cols);
	Room**& operator[](int row) const;
	void setRoom(int row, int col, Room* room);
	~Maze();
};