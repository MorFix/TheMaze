#include <iostream>

#pragma once
enum class MoveSide {
	Up,
	Left,
	Down,
	Right
};

std::ostream& operator << (std::ostream& out, const MoveSide value);