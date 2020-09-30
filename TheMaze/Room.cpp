#include <stdio.h>
#include "Room.h"

Room::Room(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen, int treasureValue)
{
	this->setData(isTopOpen, isLeftOpen, isBottomOpen, isRightOpen, treasureValue);
}

Room::Room(const Room& other) {
	this->setData(other.isTopOpen(), other.isLeftOpen(), other.isBottomOpen(), other.isRightOpen(), other.getTreasureValue());
	this->_players = other._players;
}

void Room::setData(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen, int treasureValue)
{
	this->_isTopOpen = isTopOpen;
	this->_isLeftOpen = isLeftOpen;
	this->_isBottomOpen = isBottomOpen;
	this->_isRightOpen = isRightOpen;

	this->setTreasureValue(treasureValue);
}

bool Room::isTopOpen() const
{
	return this->_isTopOpen;
}

bool Room::isLeftOpen() const
{
	return this->_isLeftOpen;
}

bool Room::isBottomOpen() const
{
	return this->_isBottomOpen;
}

bool Room::isRightOpen() const
{
	return this->_isRightOpen;
}

int Room::getTreasureValue() const
{
	return this->_treasureValue;
}

void Room::setTreasureValue(int value)
{
	this->_treasureValue = value;
}

bool Room::hasPlayer(Player* player)
{
	return std::find(this->_players.begin(), this->_players.end(), player) != this->_players.end();
}

void Room::addPlayer(Player* player)
{
	this->_players.push_back(player);
}

void Room::removePlayer(Player* player)
{
	std::vector<Player*>::iterator newEnd = std::remove(this->_players.begin(), this->_players.end(), player);

	return;
}
