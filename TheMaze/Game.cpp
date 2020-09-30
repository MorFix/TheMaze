#include <iostream>
#include "Game.h"
#include "UserPlayer.h"
#include "CpuPlayer.h"
#include "RandomMazeCreator.h"

#define MAX_TREASURE_VALUE 10

Game::Game(int numberOfPlayers, bool isUserPlaying, int rounds)
{
	this->_numberOfPlayers = numberOfPlayers;
	this->_players = this->createPlayers(numberOfPlayers, isUserPlaying);
	this->_rounds = rounds;
}

void Game::play()
{
	for (int i = 0; i < this->_rounds; i++) {
		Maze maze = this->createMaze();
		bool isRoundOver = false;
		
		while (!isRoundOver) {
			for (int j = 0; !isRoundOver && j < this->_numberOfPlayers; j++) {
				Player* currentPlayer = this->_players[j];
				Location playerLocation = maze.findPlayer(currentPlayer);

				// Is the player still in the game?
				if (playerLocation != Location::NoLocation) {
					std::cout << "Player " << j + 1 << " is playing..." << std::endl;
					isRoundOver = playMove(currentPlayer, playerLocation, maze);
				}
				else {
					std::cout << "Player " << j + 1 << " is out of the game" << std::endl;
				}

				std::cout << std::endl;
			}
		}

		std::cout << "Round " << i + 1 << " is over!" << std::endl;
		this->updatePlayersScore();
	}
}

Player** Game::createPlayers(int numberOfPlayers, bool isUserPlaying) {
	Player** players = new Player * [numberOfPlayers];

	for (int i = 0; i < numberOfPlayers - 1; i++) {
		players[i] = new CpuPlayer();
	}

	if (isUserPlaying) {
		players[numberOfPlayers - 1] = new UserPlayer();
	}
	else {
		players[numberOfPlayers - 1] = new CpuPlayer();
	}

	return players;
}

Maze Game::createMaze()
{
	Maze maze = RandomMazeCreator::create();

	std::vector<Location> treasuresLocations = this->placeTreasures(maze);
	this->resetPlayers(maze, treasuresLocations);

	return maze;
}

std::vector<Location> Game::placeTreasures(Maze& maze)
{
	std::vector<Location> treasuresLocations;

	std::vector<Location> externalRooms = maze.getExternalRooms();
	size_t externalRoomsCount = externalRooms.size();
	int treasuresCount = rand() % externalRoomsCount + 1;

	for (int i = 0; i < treasuresCount; i++) {
		Location externalRoom = externalRooms[i];
		
		treasuresLocations.push_back(externalRoom);

		// Adding 1 to make sure the treasure is not 0
		maze[externalRoom]->setTreasureValue(rand() % MAX_TREASURE_VALUE + 1);
	}

	return treasuresLocations;
}

void Game::resetPlayers(Maze& maze, std::vector<Location> treasuresLocations)
{
	this->resetPlayersMoves();

	size_t treasuresLocationsCount = treasuresLocations.size();
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		Location randomTreasureLocation = treasuresLocations[rand() % treasuresLocationsCount];

		std::vector<Location> connectedRooms = maze.getConnectedExternalRooms(randomTreasureLocation.getRow(), randomTreasureLocation.getCol());
		size_t connectedRoomsCount = connectedRooms.size();

		Location randomRoom = connectedRooms[rand() % connectedRoomsCount];
		maze[randomRoom]->addPlayer(this->_players[i]);
	}
}

void Game::resetPlayersMoves()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		this->_players[i]->setNumberOfMoves(0);
	}
}

bool Game::playMove(Player* player, Location& playerLocation, Maze& maze)
{
	Move* move = player->askForMove();
	Location newLocation = move->perform(player, playerLocation, maze);
	delete move;

	// Is the new location inside the game?
	if (newLocation == Location::NoLocation) {
		return false;
	}

	int treasure = maze[newLocation]->getTreasureValue();
	if (treasure == 0) {
		return false;
	}

	player->setScore(player->getScore() + treasure);
	
	return true;
}

void Game::updatePlayersScore()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		Player* currentPlayer = this->_players[i];

		currentPlayer->setScore(currentPlayer->getScore() - currentPlayer->getNumberOfMoves());
	}
}

Game::~Game()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		delete this->_players[i];
	}

	delete[] this->_players;
}
