#include <ctime>
#include <cstdlib>
#include "RandomMazeCreator.h"

Maze RandomMazeCreator::create()
{
	srand((unsigned int)time(NULL));
	int randomMazeNum = rand() % 5;

	switch (randomMazeNum)
	{
		case 1: return RandomMazeCreator::createMaze1();
		case 2: return RandomMazeCreator::createMaze2();
		case 3: return RandomMazeCreator::createMaze3();
		case 4: return RandomMazeCreator::createMaze4();
		case 5: return RandomMazeCreator::createMaze5();
		default: return Maze(1, 1);
	}
}

Maze RandomMazeCreator::createMaze1()
{
	Maze maze = Maze(5, 5);
	
	maze.setRoom(0, 0, new Room(true, true, false, true));
	maze.setRoom(0, 1, new Room(false, true, true, true));
	
	return maze;
}

Maze RandomMazeCreator::createMaze2()
{
	Maze maze = Maze(4, 3);
	// TODO: Create the random maze
	return maze;
}

Maze RandomMazeCreator::createMaze3()
{
	Maze maze = Maze(6, 3);
	// TODO: Create the random maze
	return maze;
}

Maze RandomMazeCreator::createMaze4()
{
	Maze maze = Maze(4, 4);
	// TODO: Create the random maze
	return maze;
}

Maze RandomMazeCreator::createMaze5()
{
	Maze maze = Maze(4, 8);
	// TODO: Create the random maze
	return maze;
}
