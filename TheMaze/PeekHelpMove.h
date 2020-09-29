#pragma once
#include "Move.h"

class PeekHelpMove : public Move
{
public:
	void perform(Player* player, Maze& maze);
};

