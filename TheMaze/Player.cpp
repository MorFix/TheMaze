#include <stdio.h>
#include "Player.h"

Player::Player()
{
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