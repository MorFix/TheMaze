#pragma once
#include "Maze.h"
#include "Location.h"

class Player;
class Maze;
class Move
{
public:
	virtual Location perform(Player* player, Location& playerLocation, Maze& maze) = 0;
protected:
	void increasePlayerMoves(Player* player);
};

