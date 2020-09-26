#pragma once
#include "Room.h"

class Maze {
private:
	Room*** _rooms;
	int _rows;
	int _cols;

	bool isExternal(Room* room);
	Room** getExternalRooms();
	Room** getConnectedExternalRooms(Room* room);
public:
	Maze(int rows, int cols);
	void setRoom(int row, int col, Room* room);
	void print();
	~Maze();
};