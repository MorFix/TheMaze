#pragma once
#include "Player.h"
#include "Move.h"

class CpuPlayer : public Player {
public:
	CpuPlayer() : Player() {}
	Move* askForMove();
};

