#pragma once
#include "Player.h"

class UserPlayer : public Player
{
public:
	UserPlayer() : Player() {}
	Move* askForMove();
};

