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
	(*this)[row][col] = room;
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
