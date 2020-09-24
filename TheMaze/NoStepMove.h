#pragma once
#include "Move.h"
#include "Maze.h"

class NoStepMove : public Move
{
public:
    void perform(Player* player, Maze& maze);
};

