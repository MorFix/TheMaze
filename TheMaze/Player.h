#pragma once
#include "Room.h"
#include "Move.h"

class Move;
class Player
{
private:
	int _score;
	int _numberOfMoves;
	Room* _currentRoom;
public:
	Player();
	virtual Move* askForMove() = 0;
	int getScore() const;
	void setScore(int score);
	Room* getCurrentRoom() const;
	void setCurrentRoom(Room* room);
	int getNumberOfMoves() const;
	void setNumberOfMoves(int numberOfMoves);
};

