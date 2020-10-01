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
		Maze maze = RandomMazeCreator::create();
		std::vector<Location> treasuresLocations = this->placeTreasures(maze);
		std::cout << maze << std::endl;
		
		this->resetPlayers(maze, treasuresLocations);
		std::cout << maze << std::endl;

		bool isRoundOver = false;
		while (!isRoundOver) {
			for (int j = 0; !isRoundOver && j < this->_numberOfPlayers; j++) {
				Player* currentPlayer = this->_players[j];
				Location playerLocation = maze.findPlayer(currentPlayer);

				// Is the player still in the game?
				if (playerLocation != Location::NoLocation) {
					std::cout << "Player " << currentPlayer->getNumber() << " is playing..." << std::endl;
					isRoundOver = playMove(currentPlayer, playerLocation, maze);
				}
				else {
					std::cout << "Player " << currentPlayer->getNumber() << " is out of the game" << std::endl;
				}

				std::cout << std::endl;
			}
		}

		std::cout << "Round " << i + 1 << " is over!" << std::endl << std::endl;

		this->updatePlayersScore();
	}
}

Player** Game::createPlayers(int numberOfPlayers, bool isUserPlaying) {
	Player** players = new Player * [numberOfPlayers];

	for (int i = 0; i < numberOfPlayers - 1; i++) {
		players[i] = new CpuPlayer(i + 1);
	}

	if (isUserPlaying) {
		players[numberOfPlayers - 1] = new UserPlayer(numberOfPlayers);
	}
	else {
		players[numberOfPlayers - 1] = new CpuPlayer(numberOfPlayers);
	}

	return players;
}

std::vector<Location> Game::placeTreasures(Maze& maze)
{
	std::vector<Location> treasuresLocations;
	std::vector<Location> externalRooms = maze.getExternalRooms();

	// Getting random number of treasures to place
	int maxTreasureIndex = (rand() % (externalRooms.size() - this->_numberOfPlayers));

	for (int i = 0; i <= maxTreasureIndex; i++) {
		// Getting random room to place the treasure in
		Location room = externalRooms[rand() % externalRooms.size()];

		std::vector<Location>::iterator newEnd = std::remove(externalRooms.begin(), externalRooms.end(), room);
		treasuresLocations.push_back(room);

		// Adding 1 to make sure the treasure is not 0
		maze[room]->setTreasureValue(rand() % MAX_TREASURE_VALUE + 1);
	}

	return treasuresLocations;
}

void Game::resetPlayers(Maze& maze, std::vector<Location> treasuresLocations)
{
	this->resetPlayersMoves();

	size_t numberOfTreasures = treasuresLocations.size();

	for (int i = 0; i < this->_numberOfPlayers; i++) {
		// Picking a path to a random treasure
		Location randTreasureLocation = treasuresLocations[rand() % numberOfTreasures];
		std::vector<Location> connectedRooms = maze.getConnectedEmptyExternalRooms(randTreasureLocation);
		
		// Making sure we choose a treasure that has a connected empty room
		while (connectedRooms.size() == 0) {
			randTreasureLocation = treasuresLocations[rand() % numberOfTreasures];
			connectedRooms = maze.getConnectedEmptyExternalRooms(randTreasureLocation);
		}

		Location randomRoom = connectedRooms[rand() % connectedRooms.size()];
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
