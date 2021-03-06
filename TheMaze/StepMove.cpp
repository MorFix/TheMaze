#include <iostream>
#include "StepMove.h"

StepMove::StepMove(MoveSide side)
{
	this->_side = side;
}

Location StepMove::perform(Player* player, Location& playerLocation, Maze& maze)
{
	Location newLocation = maze.getMoveInDirection(playerLocation, this->_side);
	maze[playerLocation]->removePlayer(player);
	
	// Player didn't run out of The Maze
	if (newLocation != Location::NoLocation) {
		maze[newLocation]->addPlayer(player);
	}
	
	if (newLocation != playerLocation) {
		this->increasePlayerMoves(player);
	}
	else {
		std::cout << "This move is impossible. The turn is over" << std::endl;
	}

	return newLocation;
}
