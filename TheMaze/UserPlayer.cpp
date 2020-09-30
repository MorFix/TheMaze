#include <iostream>
#include "UserPlayer.h"
#include "NoStepMove.h"
#include "PeekHelpMove.h"
#include "DistanceHelpMove.h"
#include "StepMove.h"

using namespace std;

MoveSide UserPlayer::getMoveSide()
{
	int moveSide = 0;

	while (moveSide < 1 || moveSide > 4) {
		cout << "Please pick a side:" << endl;
		cout << "1 - Up" << endl;
		cout << "2 - Left" << endl;
		cout << "3 - Bottom" << endl;
		cout << "4 - Right" << endl;
		cin >> moveSide;
	}

	return (MoveSide) (moveSide - 1);
}

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
		case 1: {
			cout << "You chose to do nothing! Moving on..." << endl;

			return new NoStepMove;
		}
		case 2:
			return new DistanceHelpMove;
		case 3: {
			cout << "Peeking ..." << endl;
			MoveSide side = this->getMoveSide();
			cout << "You chose to PEEK " << side << endl;
			
			return new PeekHelpMove(side);
		}
		case 4: {
			cout << "Stepping ..." << endl;
			MoveSide side = this->getMoveSide();
			cout << "You chose to STEP " << side << endl;

			return new StepMove(side);
		}
		default:
			return NULL;
	}
}
