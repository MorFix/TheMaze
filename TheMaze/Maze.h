#pragma once
#include <iostream>
#include "Room.h"
#include "Location.h"
#include "MoveSide.h"

class Room;
class Player;
class Maze {
private:
	Room*** _rooms;
	int _rows;
	int _cols;

	friend std::ostream& operator<<(std::ostream& out, const Maze& maze);
	bool isExternal(Room* room);
	Room** getExternalRooms();
	Room** getConnectedExternalRooms(Room* room);
public:
	Maze(int rows, int cols);
	Maze(const Maze& other);
	void setData(int rows, int cols);
	Room**& operator[](int row) const;
	void setRoom(int row, int col, Room* room);
	Location findPlayer(Player* player);
	Location getMoveInDirection(Location& sourceLocation, MoveSide direction);
	~Maze();
};