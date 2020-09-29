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
			// TODO: should this loop be here? or in the maze?
			for (int j = 0; j < this->_numberOfPlayers; j++) {
				Player* currentPlayer = this->_players[j];
				Move* move = currentPlayer->askForMove();
				move->perform(currentPlayer, maze);
				delete move;

				// TODO: break if the last move won the round (isRoundOver = true)
				// TODO: Give points to the players
				if (false) {
					isRoundOver = true;
					break;
				}
			}
		}
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

	// TODO: place the treasues and make sure the players can get them
	this->placePlayers(maze);

	return maze;
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
