#pragma once
#include "Player.h"
#include "Move.h"

class CpuPlayer : public Player {
protected:
	MoveSide getMoveSide();
public:
	CpuPlayer() : Player() {}
	Move* askForMove();
};

