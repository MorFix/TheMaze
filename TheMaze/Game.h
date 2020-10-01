#pragma once
#include "Maze.h"
#include "Player.h"
#include "Location.h"

class Game {
private:
	int _rounds;
	int _numberOfPlayers;
	Player** _players;
	Player** createPlayers(int numberOfCpuPlayers, int numberOfUsers);
	void resetPlayersMoves();
	void playRound(int number, Maze& maze, bool printingAfterMove);
	bool playMove(Player* player, Location& playerLocation, Maze& maze);
	std::vector<Location> placeTreasures(Maze& maze);
	void resetPlayers(Maze& maze, std::vector<Location>& treasuresLocations);
	void updatePlayersScore();
	void printScore();
public:
	Game(int numberOfCpuPlayers, int numberOfUsers, int rounds);
	void play(bool printingAfterMove = true);
	~Game();
};