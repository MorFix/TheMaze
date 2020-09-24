#pragma once
#include "Treasure.h"

class Room
{
private:
	Treasure* _treasure;
	bool _isTopOpen;
	bool _isLeftOpen;
	bool _isBottomOpen;
	bool _isRightOpen;
	void clearTreasure();
public:
	Room(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen);
	Treasure* getTreasure();
	void setTreasure(int value);
	~Room();
};

