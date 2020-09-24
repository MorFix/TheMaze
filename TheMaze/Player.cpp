#include <stdio.h>
#include "Player.h"

Player::Player()
{
    this->setCurrentRoom(NULL);
    this->setScore(0);
    this->setNumberOfMoves(0);
}

int Player::getScore() const
{
    return this->_score;
}

void Player::setScore(int score)
{
    this->_score = score;
}

int Player::getNumberOfMoves() const
{
    return this->_numberOfMoves;
}

void Player::setNumberOfMoves(int numberOfMoves)
{
    this->_numberOfMoves = numberOfMoves;
}

Room* Player::getCurrentRoom() const
{
    return this->_currentRoom;
}

void Player::setCurrentRoom(Room* room)
{
    this->_currentRoom = room;
}
