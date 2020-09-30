#pragma once
#include "Move.h"
#include "MoveSide.h"

class Move;
class Player
{
private:
	int _score;
	int _numberOfMoves;
protected:
	virtual MoveSide getMoveSide() = 0;
public:
	Player();
	virtual Move* askForMove() = 0;
	int getScore() const;
	void setScore(int score);
	int getNumberOfMoves() const;
	void setNumberOfMoves(int numberOfMoves);
};

