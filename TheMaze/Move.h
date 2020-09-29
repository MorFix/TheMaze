#pragma once
#include "Maze.h"

class Player;
class Maze;
class Move
{
public:
	virtual void perform(Player* player, Maze& maze) = 0;
protected:
	void increasePlayerMoves(Player* player);
};

