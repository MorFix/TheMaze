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
		case 1:
			return new NoStepMove;
		case 2:
			return new DistanceHelpMove;
		case 3:
			// TODO: Choose a random room to peek
			return new PeekHelpMove;
		case 4:
			// TODO: Choose a random room to step to
			return new StepMove;
		default:
			return NULL;
	}

}