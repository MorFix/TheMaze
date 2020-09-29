#include <iostream>
#include "UserPlayer.h"
#include "NoStepMove.h"
#include "PeekHelpMove.h"
#include "DistanceHelpMove.h"
#include "StepMove.h"
using namespace std;



Move* UserPlayer::askForMove() {
	int moveInput = 0;

	while (moveInput < 1 || moveInput > 4) {
		cout << "It's your turn ! what do you want to do ?" << endl;
		cout << "1 - Stay where you are" << endl;
		cout << "2 - Getting help and get distance to the nearest treasure" << endl;
		cout << "3 - Getting help and peek" << endl;
		cout << "4 - Move to another room" << endl;
		cin >> moveInput;
	}

	switch (moveInput)
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
