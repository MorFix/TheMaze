#include <iostream>
#include "Game.h"
#include "CpuPlayer.h"
#include "UserPlayer.h"

using namespace std;

int main() {
	int numberOfPlayers = 0, rounds, isUserPlaying = -1;

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

	Game game(numberOfPlayers, (bool) isUserPlaying, rounds);
	
	game.play();

	cout << "Game is OVER!" << endl << "Score:" << endl;
	// TODO: print score

	return 0;
}