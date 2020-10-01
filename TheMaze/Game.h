#pragma once
#include "Maze.h"
#include "Player.h"
#include "Location.h"

class Game {
private:
	int _rounds;
	int _numberOfPlayers;
	Player** _players;
	Player** createPlayers(int numberOfPlayers, bool isUserPlaying);
	void resetPlayersMoves();
	void playRound(int number, Maze& maze, bool printingAfterMove);
	bool playMove(Player* player, Location& playerLocation, Maze& maze);
	std::vector<Location> placeTreasures(Maze& maze);
	void resetPlayers(Maze& maze, std::vector<Location> treasuresLocations);
	void updatePlayersScore();
public:
	Game(int numberOfPlayers, bool isUserPlaying, int rounds);
	void play(bool printingAfterMove = true);
	void printScore();
	~Game();
};