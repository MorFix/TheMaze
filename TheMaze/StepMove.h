#pragma once
#include "Move.h"
#include "Maze.h"

class StepMove : public Move
{
public:
	void perform(Player* player, Maze& maze);
};

