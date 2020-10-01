#pragma once
#include "Player.h"

class UserPlayer : public Player
{
protected:
	MoveSide getMoveSide();
public:
	UserPlayer(int number) : Player(number) {}
	Move* askForMove();
};

