#include <iostream>
#include "PeekHelpMove.h"

PeekHelpMove::PeekHelpMove(MoveSide side)
{
	this->_side = side;
}

Location PeekHelpMove::perform(Player* player, Location& playerLocation, Maze& maze)
{
	Location peekLocation = maze.getMoveInDirection(playerLocation, this->_side);
	if (peekLocation == Location::NoLocation) {
		std::cout << "This room is outside the borders of the maze" << std::endl;
	}
	else {
		Room* room = maze[peekLocation.getRow()][peekLocation.getCol()];
		std::cout << "There is a room to your " << this->_side << " and it's value is: " << room->getTreasureValue() << std::endl;
	}
	
	this->increasePlayerMoves(player);

	return playerLocation;
}