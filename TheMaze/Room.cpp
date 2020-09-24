#include <stdio.h>
#include "Room.h"

Room::Room(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen)
{
	this->_isTopOpen = isTopOpen;
	this->_isLeftOpen = isLeftOpen;
	this->_isBottomOpen = isBottomOpen;
	this->_isRightOpen = isRightOpen;
	this->_treasure = NULL;
}

Treasure* Room::getTreasure()
{
	return this->_treasure;
}

void Room::clearTreasure() {
	Treasure* treausre = this->getTreasure();

	if (treausre != NULL) {
		delete treausre;
	}
}

void Room::setTreasure(int value)
{
	clearTreasure();
	this->_treasure = new Treasure(value);
}

Room::~Room()
{
	clearTreasure();
}
