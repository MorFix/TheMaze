#pragma once
#include "Move.h"
#include "Maze.h"

class StepMove : public Move
{
private:
	MoveSide _side;
public:
	StepMove(MoveSide side);
	Location perform(Player* player, Location& playerLocation, Maze& maze);
};

