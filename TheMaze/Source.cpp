#include "Game.h"
#include "CpuPlayer.h"
#include "UserPlayer.h"
#include <iostream>

using namespace std;

Player** createPlayers(int numberOfPlayers, bool isUserPlaying);

int main() {
	int numberOfPlayers, rounds;
	bool isUserPlaying;

	cout << "How many players?" << endl;
	cin >> numberOfPlayers;
	cout << "How many rounds?" << endl;
	cin >> rounds;

	cout << "Is the user playing? 0 for no, 1 for yes" << endl;
	cin >> isUserPlaying;

	Player** players = createPlayers(numberOfPlayers, isUserPlaying);
	Game game(numberOfPlayers, players, rounds);
	
	game.play();

	return 0;
}

Player** createPlayers(int numberOfPlayers, bool isUserPlaying) {
	Player** players = new Player * [numberOfPlayers];

	for (int i = 0; i < numberOfPlayers - 1; i++) {
		players[i] = new CpuPlayer();
	}

	if (isUserPlaying) {
		players[numberOfPlayers - 2] = new UserPlayer();
	}
	else {
		players[numberOfPlayers - 2] = new CpuPlayer();
	}

	return players;
}