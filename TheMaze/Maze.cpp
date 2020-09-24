#include <stdio.h>
#include "Maze.h"

Maze::Maze(int rows, int cols)
{
	this->_rows = rows;
	this->_cols = cols;
	this->_rooms = new Room**[rows];
	
	for (int i = 0; i < rows; i++) {
		this->_rooms[i] = new Room*[cols];

		for (int j = 0; j < cols; j++) {
			this->_rooms[i][j] = NULL;
		}
	}
}

bool Maze::isExternal(Room* room)
{
	return false;
}

Room** Maze::getExternalRooms()
{
	return NULL;
}

Room** Maze::getConnectedExternalRooms(Room* room)
{
	return NULL;
}

void Maze::setRoom(int row, int col, Room* room)
{
	// TODO: Check the room is valid (4 directions)
	this->_rooms[row][col] = room;
}

Maze::~Maze()
{
	for (int i = 0; i < this->_rows; i++) {
		for (int j = 0; j < this->_cols; j++) {
			if (this->_rooms[i][j] != NULL) {
				delete this->_rooms[i][j];
			}
		}

		delete[] this->_rooms[i];
	}

	delete[] this->_rooms;
}
