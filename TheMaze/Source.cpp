#include <ctime>
#include <iostream>
#include "Game.h"
#include "CpuPlayer.h"
#include "UserPlayer.h"

using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int numberOfPlayers = 0, rounds, isUserPlaying = -1, isPrintingAfterMove = -1;

	while (numberOfPlayers <= 0) {
		cout << "How many players?" << endl;
		cin >> numberOfPlayers;
	}
	
	while (isUserPlaying != 0 && isUserPlaying != 1) {
		cout << "Is the user playing? 0 for no, 1 for yes" << endl;
		cin >> isUserPlaying;
	}

	cout << "How many rounds?" << endl;
	cin >> rounds;

	while (isPrintingAfterMove != 0 && isPrintingAfterMove != 1) {
		cout << "Print after each move? 0 for no, 1 for yes" << endl;
		cin >> isPrintingAfterMove;
	}

	cout << endl;

	Game game(numberOfPlayers, (bool) isUserPlaying, rounds);
	game.play((bool) isPrintingAfterMove);

	cout << "Game is OVER!" << endl << "Score:" << endl;
	game.printScore();

	return 0;
}