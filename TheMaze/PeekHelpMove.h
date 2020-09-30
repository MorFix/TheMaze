#pragma once
#include "Move.h"

class PeekHelpMove : public Move
{
private:
	MoveSide _side;
public:
	PeekHelpMove(MoveSide side);
	Location perform(Player* player, Location& playerLocation, Maze& maze);
};

