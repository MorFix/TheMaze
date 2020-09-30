#include <ctime>
#include <iostream>
#include "CpuPlayer.h"
#include "NoStepMove.h"
#include "PeekHelpMove.h"
#include "DistanceHelpMove.h"
#include "StepMove.h"

using namespace std;

MoveSide CpuPlayer::getMoveSide()
{
	srand((unsigned int)time(NULL));
	int randomMoveSide = rand() % 4;

	return (MoveSide) randomMoveSide;
}

Move* CpuPlayer::askForMove() {
	srand((unsigned int)time(NULL));
	int randomMoveNum = rand() % 4;

	switch (randomMoveNum)
	{
		case 1: {
			cout << "CPU chose to do nothing" << endl;

			return new NoStepMove;
		}
		case 2:
			return new DistanceHelpMove;
		case 3: {
			MoveSide side = this->getMoveSide();
			cout << "CPU is PEEKING " << side << endl;

			return new PeekHelpMove(side);
		}
		case 4: {
			MoveSide side = this->getMoveSide();
			cout << "CPU is STEPPING  " << side << endl;

			return new StepMove(side);
		}
		default:
			return NULL;
	}
}