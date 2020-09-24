#pragma once
#include "Maze.h"

class RandomMazeCreator
{
public:
	static Maze create();
private:
	static Maze createMaze1();
	static Maze createMaze2();
	static Maze createMaze3();
	static Maze createMaze4();
	static Maze createMaze5();
};

