#include <ctime>
#include <cstdlib>
#include "RandomMazeCreator.h"

Maze RandomMazeCreator::create()
{
	srand((unsigned int)time(NULL));
	int randomMazeNum = rand() % 5;

	switch (randomMazeNum)
	{
		case 0: return RandomMazeCreator::createMaze1();
		case 1: return RandomMazeCreator::createMaze2();
		case 2: return RandomMazeCreator::createMaze3();
		case 3: return RandomMazeCreator::createMaze4();
		case 4: return RandomMazeCreator::createMaze5();
		default: return Maze(1, 1);
	}
}

Maze RandomMazeCreator::createMaze1()
{
	Maze maze = Maze(5, 5);
	
	maze.setRoom(0, 0, new Room(true, true, false, true));
	maze.setRoom(0, 1, new Room(false, true, true, true));
	maze.setRoom(0, 2, new Room(false, true, true, true));
	maze.setRoom(0, 3, new Room(true, true, false, false));
	maze.setRoom(0, 4, new Room(false, false, true, true));
	maze.setRoom(1, 0, new Room(false, false, false, false));
	maze.setRoom(1, 1, new Room(true, false, true, false));
	maze.setRoom(1, 2, new Room(true, false, false, false));
	maze.setRoom(1, 3, new Room(false, false, true, true));
	maze.setRoom(1, 4, new Room(true, true, true, true)); 
	maze.setRoom(2, 0, new Room(false, false, true, true)); 
	maze.setRoom(2, 1, new Room(true, true, false, false)); 
	maze.setRoom(2, 2, new Room(false, false, true, true)); 
	maze.setRoom(2, 3, new Room(true, true, false, false)); 
	maze.setRoom(2, 4, new Room(true, false, true, true));
	maze.setRoom(3, 0, new Room(true, false, true, true));
	maze.setRoom(3, 1, new Room(false, true, true, true));
	maze.setRoom(3, 2, new Room(true, true, false, true));
	maze.setRoom(3, 3, new Room(false, true, true, false));
	maze.setRoom(3, 4, new Room(true, false, false, true));
	maze.setRoom(4, 0, new Room(true, true, false, false));
	maze.setRoom(4, 1, new Room(true, false, true, false));
	maze.setRoom(4, 2, new Room(false, false, false, false));
	maze.setRoom(4, 3, new Room(true, false, false, true));
	maze.setRoom(4, 4, new Room(false, true, false, true));

	return maze;
}

Maze RandomMazeCreator::createMaze2()
{
	Maze maze = Maze(9, 3);

	maze.setRoom(0, 0, new Room(false, false, true, true));
	maze.setRoom(0, 1, new Room(true, true, true, false));
	maze.setRoom(0, 2, new Room(false, false, true, true));
	maze.setRoom(1, 1, new Room(true, true, false, true));
	maze.setRoom(1, 2, new Room(true, true, true, false));
	maze.setRoom(2, 1, new Room(false, false, true, true));
	maze.setRoom(2, 2, new Room(true, true, true, false));
	maze.setRoom(3, 0, new Room(false, false, false, true));
	maze.setRoom(3, 1, new Room(true, true, true, false));
	maze.setRoom(3, 2, new Room(true, false, false, false));
	maze.setRoom(4, 1, new Room(true, false, true, false));
	maze.setRoom(5, 1, new Room(true, false, true, true));
	maze.setRoom(5, 2, new Room(false, true, false, false));
	maze.setRoom(6, 0, new Room(false, false, true, true));
	maze.setRoom(6, 1, new Room(true, true, false, true));
	maze.setRoom(7, 0, new Room(true, false, true, true));
	maze.setRoom(7, 2, new Room(false, true, true, true));
	maze.setRoom(8, 0, new Room(true, false, true, true));
	maze.setRoom(8, 1, new Room(false, true, false, true));
	maze.setRoom(8, 2, new Room(true, true, false, false));

	return maze;
}

Maze RandomMazeCreator::createMaze3()
{
	Maze maze = Maze(4, 7);
	
	maze.setRoom(0, 2, new Room(false, false, true, true));
	maze.setRoom(0, 3, new Room(false, true, false, true));
	maze.setRoom(0, 5, new Room(true, false, true, true));
	maze.setRoom(1, 0, new Room(false, true, false, true));
	maze.setRoom(1, 1, new Room(false, true, true, false));
	maze.setRoom(1, 2, new Room(true, false, false, true));
	maze.setRoom(1, 3, new Room(false, true, false, true));
	maze.setRoom(1, 4, new Room(false, true, false, true));
	maze.setRoom(1, 5, new Room(true, true, true, false));
	maze.setRoom(2, 1, new Room(true, false, false, true));
	maze.setRoom(2, 2, new Room(false, true, true, false));
	maze.setRoom(2, 5, new Room(true, true, true, true));
	maze.setRoom(2, 6, new Room(false, true, true, false));
	maze.setRoom(3, 0, new Room(false, true, false, true));
	maze.setRoom(3, 1, new Room(false, true, false, true));
	maze.setRoom(3, 2, new Room(true, true, false, false));
	maze.setRoom(3, 5, new Room(true, false, false, true));
	maze.setRoom(3, 6, new Room(true, true, true, true));

	return maze;
}

Maze RandomMazeCreator::createMaze4()
{
	Maze maze = Maze(6, 11);

	maze.setRoom(0, 0, new Room(true, false, true, false));
	maze.setRoom(0, 2, new Room(true, false, true, false));
	maze.setRoom(0, 4, new Room(true, false, true, false));
	maze.setRoom(0, 6, new Room(false, false, true, false));
	maze.setRoom(0, 8, new Room(false, false, true, false));
	maze.setRoom(0, 10, new Room(false, false, true, false));
	maze.setRoom(1, 0, new Room(true, false, false, true));
	maze.setRoom(1, 1, new Room(false, true, false, true));
	maze.setRoom(1, 2, new Room(true, true, true, false));
	maze.setRoom(1, 3, new Room(false, false, false, true));
	maze.setRoom(1, 4, new Room(true, true, true, false));
	maze.setRoom(1, 5, new Room(false, false, false, false));
	maze.setRoom(1, 6, new Room(true, false, true, false));
	maze.setRoom(1, 7, new Room(true, false, false, true));
	maze.setRoom(1, 8, new Room(true, true, true, true));
	maze.setRoom(1, 9, new Room(false, true, true, true));
	maze.setRoom(1, 10, new Room(true, true, true, false));
	maze.setRoom(2, 0, new Room(false, false, true, true));
	maze.setRoom(2, 2, new Room(true, false, false, false));
	maze.setRoom(2, 4, new Room(true, false, true, false));
	maze.setRoom(2, 6, new Room(true, false, true, true));
	maze.setRoom(2, 8, new Room(true, false, true, false));
	maze.setRoom(2, 10, new Room(true, false, true, false));
	maze.setRoom(3, 0, new Room(true, false, false, true));
	maze.setRoom(3, 1, new Room(false, true, false, true));
	maze.setRoom(3, 2, new Room(false, true, false, true));
	maze.setRoom(3, 3, new Room(false, true, false, true));
	maze.setRoom(3, 4, new Room(true, true, false, true));
	maze.setRoom(3, 5, new Room(false, true, false, true));
	maze.setRoom(3, 6, new Room(true, true, false, false));
	maze.setRoom(3, 7, new Room(false, false, false, true));
	maze.setRoom(3, 8, new Room(true, true, true, true));
	maze.setRoom(3, 9, new Room(false, true, false, false));
	maze.setRoom(3, 10, new Room(true, false, true, true));
	maze.setRoom(4, 0, new Room(false, true, true, false));
	maze.setRoom(4, 2, new Room(false, false, false, false));
	maze.setRoom(4, 4, new Room(false, true, true, false));
	maze.setRoom(4, 6, new Room(false, false, true, false));
	maze.setRoom(4, 8, new Room(true, false, false, false));
	maze.setRoom(4, 10, new Room(true, false, false, false));
	maze.setRoom(5, 0, new Room(true, false, true, true));
	maze.setRoom(5, 1, new Room(false, true, false, true));
	maze.setRoom(5, 2, new Room(false, true, false, true));
	maze.setRoom(5, 3, new Room(false, true, false, true));
	maze.setRoom(5, 4, new Room(true, true, false, true));
	maze.setRoom(5, 5, new Room(false, true, false, true));
	maze.setRoom(5, 6, new Room(true, true, false, true));
	maze.setRoom(5, 7, new Room(false, true, false, true));
	maze.setRoom(5, 8, new Room(false, true, false, true));
	maze.setRoom(5, 9, new Room(false, true, false, true));
	maze.setRoom(5, 10, new Room(false, true, false, true));

	return maze;
}

Maze RandomMazeCreator::createMaze5()
{
	Maze maze = Maze(9, 10);

	maze.setRoom(0, 1, new Room(true, false, true, false));
	maze.setRoom(0, 2, new Room(false, false, false, true));
	maze.setRoom(0, 3, new Room(true, true, true, false));
	maze.setRoom(0, 5, new Room(false, false, false, true));
	maze.setRoom(0, 6, new Room(false, true, false, true));
	maze.setRoom(0, 7, new Room(true, true, false, true));
	maze.setRoom(0, 8, new Room(false, true, true, false));
	maze.setRoom(1, 0, new Room(false, true, false, true));
	maze.setRoom(1, 1, new Room(true, true, false, false));
	maze.setRoom(1, 3, new Room(true, false, true, false));
	maze.setRoom(1, 4, new Room(false, false, true, true));
	maze.setRoom(1, 5, new Room(false, true, true, false));
	maze.setRoom(1, 7, new Room(false, true, true, false));
	maze.setRoom(1, 8, new Room(true, false, false, true));
	maze.setRoom(1, 9, new Room(false, true, true, false));
	maze.setRoom(2, 0, new Room(false, false, true, false));
	maze.setRoom(2, 2, new Room(false, true, false, true));
	maze.setRoom(2, 3, new Room(true, true, true, true));
	maze.setRoom(2, 4, new Room(true, true, false, false));
	maze.setRoom(2, 5, new Room(true, false, true, false));
	maze.setRoom(2, 6, new Room(false, false, false, true));
	maze.setRoom(2, 7, new Room(true, true, true, false));
	maze.setRoom(2, 9, new Room(true, false, true, false));
	maze.setRoom(3, 0, new Room(true, true, false, true));
	maze.setRoom(3, 1, new Room(false, true, true, false));
	maze.setRoom(3, 3, new Room(true, false, false, true));
	maze.setRoom(3, 4, new Room(false, true, false, false));
	maze.setRoom(3, 5, new Room(true, false, false, true));
	maze.setRoom(3, 7, new Room(true, false, true, true));
	maze.setRoom(3, 8, new Room(false, true, true, false));
	maze.setRoom(3, 9, new Room(true, false, true, false));
	maze.setRoom(4, 1, new Room(true, false, true, false));
	maze.setRoom(4, 2, new Room(false, false, true, true));
	maze.setRoom(4, 3, new Room(false, true, true, false));
	maze.setRoom(4, 4, new Room(false, false, true, true));
	maze.setRoom(4, 5, new Room(false, true, true, false));
	maze.setRoom(4, 6, new Room(false, false, false, true));
	maze.setRoom(4, 7, new Room(true, true, false, false));
	maze.setRoom(4, 8, new Room(true, false, true, false));
	maze.setRoom(5, 0, new Room(false, true, true, true));
	maze.setRoom(5, 1, new Room(true, true, false, false));
	maze.setRoom(5, 3, new Room(true, false, false, true));
	maze.setRoom(5, 4, new Room(true, true, false, false));
	maze.setRoom(5, 5, new Room(true, false, true, true));
	maze.setRoom(5, 7, new Room(false, false, true, true));
	maze.setRoom(5, 8, new Room(true, true, false, false));
	maze.setRoom(5, 9, new Room(false, false, true, false));
	maze.setRoom(6, 0, new Room(true, false, true, false));
	maze.setRoom(6, 2, new Room(false, false, false, true));
	maze.setRoom(6, 3, new Room(false, true, true, true));
	maze.setRoom(6, 4, new Room(false, true, true, false));
	maze.setRoom(6, 5, new Room(true, false, true, false));
	maze.setRoom(6, 7, new Room(true, false, true, false));
	maze.setRoom(6, 9, new Room(true, false, true, false));
	maze.setRoom(7, 0, new Room(true, false, false, true));
	maze.setRoom(7, 1, new Room(false, true, false, true));
	maze.setRoom(7, 2, new Room(false, true, true, false));
	maze.setRoom(7, 4, new Room(true, false, true, false));
	maze.setRoom(7, 5, new Room(true, false, false, true));
	maze.setRoom(7, 6, new Room(false, true, true, false));
	maze.setRoom(7, 8, new Room(false, false, true, true));
	maze.setRoom(7, 9, new Room(true, true, false, false));
	maze.setRoom(8, 2, new Room(true, false, false, true));
	maze.setRoom(8, 3, new Room(false, true, false, true));
	maze.setRoom(8, 4, new Room(true, true, false, false));
	maze.setRoom(8, 6, new Room(true, false, false, true));
	maze.setRoom(8, 7, new Room(false, true, false, true));
	maze.setRoom(8, 8, new Room(true, true, false, false));

	return maze;
}
