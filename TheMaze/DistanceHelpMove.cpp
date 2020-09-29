#include "DistanceHelpMove.h"

void DistanceHelpMove::perform(Player* player, Maze& maze)
{
    Location playerLocation = maze.findPlayer(player);
    // TODO: find the closest treasure and print the distance to it
    this->increasePlayerMoves(player);
}
