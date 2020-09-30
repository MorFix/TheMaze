#pragma once
#include "Move.h"
#include "Maze.h"

class NoStepMove : public Move
{
public:
    Location perform(Player* player, Location& playerLocation, Maze& maze);
};

