#include <iostream>
#include "Game.h"
#include "CpuPlayer.h"
#include "UserPlayer.h"

using namespace std;

int main() {
	int numberOfPlayers, rounds;
	bool isUserPlaying;

	cout << "How many players?" << endl;
	cin >> numberOfPlayers;
	
	// TODO: input checks for this
	cout << "Is the user playing? 0 for no, 1 for yes" << endl;
	cin >> isUserPlaying;

	cout << "How many rounds?" << endl;
	cin >> rounds;

	Game game(numberOfPlayers, isUserPlaying, rounds);
	
	game.play();

	return 0;
}