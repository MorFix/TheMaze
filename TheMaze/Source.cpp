#include <ctime>
#include <iostream>
#include "Game.h"
#include "CpuPlayer.h"
#include "UserPlayer.h"

using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	int numberOfCpuPlayers = -1, numberOfUsers = -1, rounds = 0, isPrintingAfterMove = -1;

	while (numberOfCpuPlayers < 0) {
		cout << "How many CPU players?" << endl;
		cin >> numberOfCpuPlayers;
	}
	
	while (numberOfUsers < 0) {
		cout << "How many USER players?" << endl;
		cin >> numberOfUsers;
	}

	if (numberOfCpuPlayers + numberOfUsers == 0) {
		return -1;
	}

	while (rounds <= 0) {
		cout << "How many rounds?" << endl;
		cin >> rounds;
	}

	while (isPrintingAfterMove != 0 && isPrintingAfterMove != 1) {
		cout << "Print after each move? 0 for no, 1 for yes" << endl;
		cin >> isPrintingAfterMove;
	}

	cout << endl;

	Game game(numberOfCpuPlayers, numberOfUsers, rounds);
	game.play((bool) isPrintingAfterMove);

	cout << "Game is OVER!" << endl;

	return 0;
}