#pragma once
#include "Maze.h"
#include "Player.h"

class Game {
private:
	int _rounds;
	int _numberOfPlayers;
	Player** _players;
	Player** createPlayers(int numberOfPlayers, bool isUserPlaying);
	Maze createMaze();
	void resetPlayersMoves();
	void placePlayers(Maze& maze);

public:
	Game(int numberOfPlayers, bool isUserPlaying, int rounds);
	void play();
	~Game();
};