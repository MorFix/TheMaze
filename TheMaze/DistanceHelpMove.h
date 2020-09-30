#pragma once
#include "Move.h"

class DistanceHelpMove : public Move
{
public:
    Location perform(Player* player, Location& playerLocation, Maze& maze);
};

