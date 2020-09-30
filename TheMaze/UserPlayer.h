#pragma once
#include "Player.h"

class UserPlayer : public Player
{
protected:
	MoveSide getMoveSide();
public:
	UserPlayer() : Player() {}
	Move* askForMove();
};

