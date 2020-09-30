#include <stdio.h>
#include <iostream>
#include "Maze.h"

using namespace std;

Maze::Maze(int rows, int cols)
{
	this->setData(rows, cols);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			(*this)[i][j] = NULL;
		}
	}
}

Maze::Maze(const Maze& other) {
	this->setData(other._rows, other._cols);

	for (int i = 0; i < other._rows; i++) {
		for (int j = 0; j < other._cols; j++) {
			if (other[i][j] != NULL) {
				(*this)[i][j] = new Room(*(other[i][j]));
			}
			else {
				(*this)[i][j] = NULL;
			}
		}
	}
}

void Maze::setData(int rows, int cols) {
	this->_rows = rows;
	this->_cols = cols;
	this->_rooms = new Room**[rows];

	for (int i = 0; i < rows; i++) {
		(*this)[i] = new Room*[cols];
	}
}

bool Maze::isExternal(Location& location)
{
	return false;
}

std::vector<Location> Maze::getExternalRooms()
{
	// TODO: implement
	return vector<Location>();
}

std::vector<Location> Maze::getConnectedExternalRooms(Location& location)
{
	// TODO: implement
	return vector<Location>();
}

void Maze::setRoom(int row, int col, Room* room)
{
	(*this)[row][col] = room;
}

Location Maze::findPlayer(Player* player)
{
	for (int i = 0; i < this->_rows; i++) {
		for (int j = 0; j < this->_cols; j++) {
			Room* currentRoom = (*this)[i][j];
			if (currentRoom != NULL && currentRoom->hasPlayer(player)) {
				return Location(i, j);
			}
		}
	}

	return Location::NoLocation;
}

Location Maze::getMoveInDirection(Location& sourceLocation, MoveSide direction)
{
	int row = sourceLocation.getRow();
	int col = sourceLocation.getCol();
	Room* currentRoom = (*this)[row][col];
	bool isSideOpen = false;

	switch (direction)
	{
		case MoveSide::Up: {
			row--;
			isSideOpen = currentRoom->isTopOpen();
			break;
		}
		case MoveSide::Left: {
			col--;
			isSideOpen = currentRoom->isLeftOpen();
			break;
		}
		case MoveSide::Down: {
			row++;
			isSideOpen = currentRoom->isBottomOpen();
			break;
		}
		case MoveSide::Right: {
			col++;
			isSideOpen = currentRoom->isRightOpen();
			break;
		}
		default:
			break;	
	}
	
	if (row < 0 || col < 0 || row >= this->_rows || col >= this->_cols || (*this)[row][col] == NULL) {
		return Location::NoLocation;
	}

	if (!isSideOpen) {
		return sourceLocation;
	}

	return Location(row, col);
}

Maze::~Maze()
{
	for (int i = 0; i < this->_rows; i++) {
		for (int j = 0; j < this->_cols; j++) {
			if ((*this)[i][j] != NULL) {
				delete (*this)[i][j];
			}
		}

		delete[] (*this)[i];
	}

	delete[] this->_rooms;
}

Room**& Maze::operator[](int row) const {
	return this->_rooms[row];
}

ostream& operator<<(ostream& out, const Maze& maze)
{
	for (int i = 0; i < maze._rows; i++) {
		for (int j = 0; j < maze._cols; j++) {
			if (maze[i][j] != NULL) {
				// TODO: print the room borders
			}

			out << "\t";
		}
	}

	return out;
}
