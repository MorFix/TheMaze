#pragma once
#include "Move.h"

class PeekHelpMove : public Move
{
	void perform(Player* player, Maze& maze);
};

