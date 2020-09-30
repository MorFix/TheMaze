#include "DistanceHelpMove.h"

Location DistanceHelpMove::perform(Player* player, Location& playerLocation, Maze& maze)
{
    // TODO: find the closest treasure and print the distance to it
    this->increasePlayerMoves(player);

    return playerLocation;
}
