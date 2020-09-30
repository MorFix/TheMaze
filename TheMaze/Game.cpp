#include <iostream>
#include "Game.h"
#include "UserPlayer.h"
#include "CpuPlayer.h"
#include "RandomMazeCreator.h"

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
					std::cout << "Player " << j << " is playing..." << std::endl;
					isRoundOver = playMove(currentPlayer, playerLocation, maze);
				}
				else {
					std::cout << "Player " << j << " is out of the game" << std::endl;
				}

				std::cout << std::endl;
			}
		}

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

	// TODO: place the treasues
	this->resetPlayers(maze);

	return maze;
}

void Game::resetPlayers(Maze& maze)
{
	this->resetPlayersMoves();
	// TODO: implement
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

	int treasure = maze[newLocation.getRow()][newLocation.getCol()]->getTreasureValue();
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
