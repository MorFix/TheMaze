#include <ctime>
#include <stdlib.h>
#include "CpuPlayer.h"

#include "NoStepMove.h"
#include "PeekHelpMove.h"
#include "DistanceHelpMove.h"
#include "StepMove.h"

Move* CpuPlayer::askForMove() {
	srand((unsigned int)time(NULL));
	int randomMoveNum = rand() % 4;

	switch (randomMoveNum)
	{
		case 0:
			return new NoStepMove;
		case 1:
			return new DistanceHelpMove;
		case 2:
			// TODO: Choose a random room to peek
			return new PeekHelpMove;
		case 3:
			// TODO: Choose a random room to step to
			return new StepMove;
		default:
			return NULL;
	}

}