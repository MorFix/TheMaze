#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "Maze.h"

#define NULL_ROOM "         "
#define DOOR_VERTICAL "+++++++++"
#define DOOR_HORIZONTAL "+"
#define WALL_VERTICAL "---------"
#define WALL_HORIZONTAL "|"

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

bool Maze::isExternal(int row, int col)
{
	Room* room = (*this)[row][col];

	return room->isTopOpen() && !this->isLocationInMaze(row - 1, col) ||
		room->isLeftOpen() && !this->isLocationInMaze(row, col - 1) ||
		room->isBottomOpen() && !this->isLocationInMaze(row + 1, col) ||
		room->isRightOpen() && !this->isLocationInMaze(row, col + 1);
}

bool Maze::isLocationInMaze(int row, int col) {
	return row >= 0 && col >= 0 && row < this->_rows && col < this->_cols && (*this)[row][col] != NULL;
}

std::vector<Location> Maze::getExternalRooms()
{
	vector<Location> rooms;

	for (int i = 0; i < this->_rows; i++) {
		for (int j = 0; j < this->_cols; j++) {
			if ((*this)[i][j] != NULL && this->isExternal(i, j)) {
				rooms.push_back(Location(i, j));
			}
		}
	}

	return rooms;
}

std::vector<Location> Maze::getConnectedEmptyExternalRooms(Location& originalRoom) {
	vector<Location> rooms;
	
	// This is to avoid searching again where we already visited (a loop)
	vector<Location> recursiveStack;
	
	Room* room = (*this)[originalRoom];
	int row = originalRoom.getRow();
	int col = originalRoom.getCol();
	
	recursiveStack.push_back(originalRoom);

	// Proccesing 4 directions of the current room, skipping the current one since it's not considered connected to itself
	addConnectedExternalRooms(row - 1, col, room->isTopOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row, col - 1, room->isLeftOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row + 1, col, room->isBottomOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row, col + 1, room->isRightOpen(), rooms, recursiveStack);

	return rooms;
}

vector<Location> Maze::getConnectedExternalRooms(int row, int col, vector<Location>& recursiveStack)
{
	vector<Location> rooms;
	Room* room = (*this)[row][col];
	Location location = Location(row, col);

	// Checking if we originally came from the current location, which means there is a loop and we ignore it
	for (int i = 0; i < recursiveStack.size(); i++) {
		if (recursiveStack[i] == location) {
			return rooms;
		}
	}

	recursiveStack.push_back(location);

	// Processing the current room (this is the recursion stop condition)
	if (this->isExternal(row, col) && room->getTreasureValue() == 0) {
		rooms.push_back(location);
	}

	// Proccesing 4 directions of the current room
	addConnectedExternalRooms(row - 1, col, room->isTopOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row, col - 1, room->isLeftOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row + 1, col, room->isBottomOpen(), rooms, recursiveStack);
	addConnectedExternalRooms(row, col + 1, room->isRightOpen(), rooms, recursiveStack);
	
	recursiveStack.erase(std::remove(recursiveStack.begin(), recursiveStack.end(), location), recursiveStack.end());

	return rooms;
}

void Maze::addConnectedExternalRooms(int row, int col, bool isPathOpen, vector<Location>& rooms, vector<Location>& recursiveStack)
{
	if (!isPathOpen || !this->isLocationInMaze(row, col)) {
		return;
	}

	vector<Location> connectedExternalRooms = getConnectedExternalRooms(row, col, recursiveStack);

	rooms.insert(rooms.end(), connectedExternalRooms.begin(), connectedExternalRooms.end());
}

vector<Location> Maze::getTreasures()
{
	vector<Location> locations;

	for (int i = 0; i < this->_rows; i++) {
		for (int j = 0; j < this->_cols; j++) {
			Room* room = (*this)[i][j];

			if (room != NULL && room->getTreasureValue() > 0) {
				locations.push_back(Location(i, j));
			}
		}
	}

	return locations;
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
	
	if (!this->isLocationInMaze(row, col)) {
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

Room*& Maze::operator[](const Location& location) const
{
	return (*this)[location.getRow()][location.getCol()];
}

ostream& operator<<(ostream& out, const Maze& maze)
{
	for (int i = 0; i < maze._rows; i++) {
		out << setw(0);
		maze.outputTopBorder(out, maze[i]);
		out << endl;

		for (int j = 0; j < maze._cols; j++) {
			Room* roomPtr = maze[i][j];
			
			if (roomPtr == NULL) {
				out << NULL_ROOM;
			}
			else {
				out << (roomPtr->isLeftOpen() ? DOOR_HORIZONTAL : WALL_HORIZONTAL)
					<< *roomPtr
					<< (roomPtr->isRightOpen() ? DOOR_HORIZONTAL : WALL_HORIZONTAL);
			}
		}

		out << endl;
		maze.outputBottomBorder(out, maze[i]);
		out << endl;
	}

	return out;
}

void Maze::outputTopBorder(ostream& out, Room** row) const
{
	for (int i = 0; i < this->_cols; i++) {
		Room* room = row[i];
		
		if (room == NULL) {
			out << NULL_ROOM;
		}
		else if (!room->isTopOpen()) {
			out << WALL_VERTICAL;
		}
		else {
			out << DOOR_VERTICAL;
		}
	}
}

void Maze::outputBottomBorder(ostream& out, Room** row) const
{
	for (int i = 0; i < this->_cols; i++) {
		Room* room = row[i];

		if (room == NULL) {
			out << NULL_ROOM;
		}
		else if (!room->isBottomOpen()) {
			out << WALL_VERTICAL;
		}
		else {
			out << DOOR_VERTICAL;
		}
	}
}