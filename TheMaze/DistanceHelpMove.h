#pragma once
#include "Move.h"

class DistanceHelpMove : public Move
{
private:
    double getDistance(Location& playerLocation, Location& treasureLocation);
public:
    Location perform(Player* player, Location& playerLocation, Maze& maze);
};

