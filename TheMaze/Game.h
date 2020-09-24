#pragma once
#include "Maze.h"
#include "Player.h"

class Game {
private:
	int _rounds;
	int _numberOfPlayers;
	Player** _players;
	Maze createMaze();
	void resetPlayersMoves();
	void placePlayers(Maze& maze);

public:
	Game(int numberOfPlayers, Player** players, int rounds);
	void play();
	~Game();
};