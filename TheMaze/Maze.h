#pragma once
#include <iostream>
#include <vector>
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
	bool isExternal(int row, int col);
	bool isLocationInMaze(int row, int col);
	std::vector<Location> getConnectedExternalRooms(int row, int col, std::vector<Location> recursiveStack);

public:
	Maze(int rows, int cols);
	Maze(const Maze& other);
	std::vector<Location> getExternalRooms();
	std::vector<Location> getConnectedExternalRooms(int row, int col);
	std::vector<Location> getTreasures();
	void setData(int rows, int cols);
	Room**& operator[](int row) const;
	Room*& operator[](const Location& location) const;
	void setRoom(int row, int col, Room* room);
	Location findPlayer(Player* player);
	Location getMoveInDirection(Location& sourceLocation, MoveSide direction);
	~Maze();
};