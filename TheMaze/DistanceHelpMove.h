#pragma once
#include "Move.h"

class DistanceHelpMove : public Move
{
public:
    void perform(Player* player, Maze& maze);
};

