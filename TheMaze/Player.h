#pragma once
#include "Move.h"

class Move;
class Player
{
private:
	int _score;
	int _numberOfMoves;
public:
	Player();
	virtual Move* askForMove() = 0;
	int getScore() const;
	void setScore(int score);
	int getNumberOfMoves() const;
	void setNumberOfMoves(int numberOfMoves);
};

