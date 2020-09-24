#include <ctime>
#include <cstdlib>
#include "Game.h"

Game::Game(int numberOfPlayers, Player** players, int rounds)
{
	this->_numberOfPlayers = numberOfPlayers;
	this->_players = players;
	this->_rounds = rounds;
}

void Game::play()
{
	for (int i = 0; i < this->_rounds; i++) {
		Maze maze = this->createMaze();
		bool isRoundOver = false;
		
		while (!isRoundOver) {
			// TODO: should this loop be here? or in the maze?
			for (int j = 0; j < this->_numberOfPlayers; j++) {
				Player* currentPlayer = this->_players[i];
				
				Move* move = currentPlayer->askForMove();
				move->perform(currentPlayer, maze);
				delete move;

				// TODO: break if the last move won the round (isRoundOver = true)
			}
		}
	}
}

Maze Game::createMaze()
{
	Maze maze = this->getRandomMaze();

	// TODO: place the treasues
	// TODO: make sure the players can get the treasures
	this->placePlayers(maze);

	return maze;
}

Maze Game::getRandomMaze()
{
	srand((unsigned int) time(NULL));
	int randomMazeNum = rand() % 5;

	switch (randomMazeNum)
	{
		case 1: {
			Maze maze = Maze(5, 5);
			// TODO: Create the random maze
			return maze;
		}
		case 2: {
			Maze maze = Maze(4, 3);
			// TODO: Create the random maze
			return maze;
		}
		case 3: {
			Maze maze = Maze(6, 3);
			// TODO: Create the random maze
			return maze;
		}	
		case 4: {
			Maze maze = Maze(4, 4);
			// TODO: Create the random maze
			return maze;
		}
		case 5: {
			Maze maze = Maze(4, 8);
			// TODO: Create the random maze
			return maze;
		}
		default:
			Maze maze = Maze(1, 1);
			return maze;
	}
}

void Game::resetPlayersMoves()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		this->_players[i]->setNumberOfMoves(0);
	}
}

void Game::placePlayers(Maze& maze)
{
	this->resetPlayersMoves();
	// TODO: implement
}

Game::~Game()
{
	for (int i = 0; i < this->_numberOfPlayers; i++) {
		delete this->_players[i];
	}

	delete[] this->_players;
}
