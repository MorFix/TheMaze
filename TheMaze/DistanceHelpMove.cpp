#include "DistanceHelpMove.h"
#include <math.h>

double DistanceHelpMove::getDistance(Location& playerLocation, Location& treasureLocation)
{
    return sqrt(pow(playerLocation.getRow() - treasureLocation.getRow(), 2) +
                pow(playerLocation.getCol() - treasureLocation.getCol(), 2));
}

Location DistanceHelpMove::perform(Player* player, Location& playerLocation, Maze& maze)
{
    std::vector<Location> treasures = maze.getTreasures();

    double closestDistance = this->getDistance(playerLocation, treasures[0]);

    for (int i = 0; i < treasures.size(); i++) {
        double distance = this->getDistance(playerLocation, treasures[i]);
        
        if (distance < closestDistance) {
            closestDistance = distance;
        }
    }
    
    std::cout << "The closest treasure is " << closestDistance << " away!" << std::endl;

    this->increasePlayerMoves(player);

    return playerLocation;
}
