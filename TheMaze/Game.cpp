#include <iostream>
#include "Game.h"
#include "UserPlayer.h"
#include "CpuPlayer.h"
#include "RandomMazeCreator.h"

#define MAX_TREASURE_VALUE 99

using namespace std;

Game::Game(int numberOfPlayers, bool isUserPlaying, int rounds)
{
	this->_numberOfPlayers = numberOfPlayers;
	this->_players = this->createPlayers(numberOfPlayers, isUserPlaying);
	this->_rounds = rounds;
}

void Game::play(bool printingAfterMove)
{
	for (int i = 0; i < this->_rounds; i++) {
		Maze maze = RandomMazeCreator::create();
		vector<Location> treasuresLocations = this->placeTreasures(maze);	
		
		this->resetPlayers(maze, treasuresLocations);
		this->playRound(i + 1, maze, printingAfterMove);
	}
}

void Game::playRound(int number, Maze& maze, bool printingAfterMove) {
	bool isRoundOver = false;
	while (!isRoundOver) {
		for (int j = 0; !isRoundOver && j < this->_numberOfPlayers; j++) {
			Player* currentPlayer = this->_players[j];
			Location playerLocation = maze.findPlayer(currentPlayer);

			// Is the player still in the game?
			if (playerLocation != Location::NoLocation) {
				cout << "Player " << currentPlayer->getNumber() << " is playing..." << endl;
				isRoundOver = this->playMove(currentPlayer, playerLocation, maze);

				if (printingAfterMove) {
					cout << maze << endl;
				}
			}
			else {
				cout << "Player " << currentPlayer->getNumber() << " is out of the game" << endl;
			}

			cout << endl;
		}
	}

	cout << "Round " << number << " is over!" << endl << endl;
	cout << maze << endl;

	this->updatePlayersScore();
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

vector<Location> Game::placeTreasures(Maze& maze)
{
	vector<Location> treasuresLocations;
	vector<Location> externalRooms = maze.getExternalRooms();

	// Getting random number of treasures to place
	int maxTreasureIndex = (rand() % (externalRooms.size() - this->_numberOfPlayers));

	for (int i = 0; i <= maxTreasureIndex; i++) {
		// Getting random room to place the treasure in
		Location room = externalRooms[rand() % externalRooms.size()];

		externalRooms.erase(remove(externalRooms.begin(), externalRooms.end(), room), externalRooms.end());
		treasuresLocations.push_back(room);

		// Adding 1 to make sure the treasure is not 0
		maze[room]->setTreasureValue(rand() % MAX_TREASURE_VALUE + 1);
	}

	return treasuresLocations;
}

void Game::resetPlayers(Maze& maze, vector<Location> treasuresLocations)
{
	this->resetPlayersMoves();

	size_t numberOfTreasures = treasuresLocations.size();

	for (int i = 0; i < this->_numberOfPlayers; i++) {
		// Picking a path to a random treasure
		Location randTreasureLocation = treasuresLocations[rand() % numberOfTreasures];
		vector<Location> connectedRooms = maze.getConnectedEmptyExternalRooms(randTreasureLocation);
		
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

	// Is the new location outside the game?
	if (newLocation == Location::NoLocation) {
		// Was it the last player to leave the maze?
		bool allPlayersOut = true;
		for (int i = 0; i < this->_numberOfPlayers; i++) {
			if (maze.findPlayer(this->_players[i]) != Location::NoLocation) {
				allPlayersOut = false;
				break;
			}
		}

		return allPlayersOut;
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

void Game::printScore()
{
	cout << "Player Number\tScore" << endl;
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		Player* player = this->_players[i];
		cout << player->getNumber() << "\t\t" << player->getScore() << endl;
	}
}

Game::~Game()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		delete this->_players[i];
	}

	delete[] this->_players;
}
