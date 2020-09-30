#include <iostream>
#include "CpuPlayer.h"
#include "NoStepMove.h"
#include "PeekHelpMove.h"
#include "DistanceHelpMove.h"
#include "StepMove.h"

using namespace std;

MoveSide CpuPlayer::getMoveSide()
{
	int randomMoveSide = rand() % 4;

	return (MoveSide) randomMoveSide;
}

Move* CpuPlayer::askForMove() {
	int randomMoveNum = rand() % 4;

	switch (randomMoveNum)
	{
		case 0: {
			cout << "CPU chose to do nothing" << endl;

			return new NoStepMove;
		}
		case 1:
			return new DistanceHelpMove;
		case 2: {
			MoveSide side = this->getMoveSide();
			cout << "CPU is PEEKING " << side << endl;

			return new PeekHelpMove(side);
		}
		case 3: {
			MoveSide side = this->getMoveSide();
			cout << "CPU is STEPPING  " << side << endl;

			return new StepMove(side);
		}
		default:
			return NULL;
	}
}