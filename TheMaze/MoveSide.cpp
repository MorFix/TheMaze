#include "MoveSide.h"

std::ostream& operator << (std::ostream& out, const MoveSide value) {
	switch (value)
	{
		case MoveSide::Up: return out << "Up";
		case MoveSide::Left: return out << "Left";
		case MoveSide::Down: return out << "Down";
		case MoveSide::Right: return out << "Right";
		default: return out;
	}
}