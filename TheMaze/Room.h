#pragma once

class Room
{
private:
	bool _isTopOpen;
	bool _isLeftOpen;
	bool _isBottomOpen;
	bool _isRightOpen;
	int _treasureValue;
	
	void setData(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen, int treasureValue);
public:
	Room(bool isTopOpen, bool isLeftOpen, bool isBottomOpen, bool isRightOpen, int treasureValue = 0);
	Room(const Room& other);
	bool isTopOpen() const;
	bool isLeftOpen() const;
	bool isBottomOpen() const;
	bool isRightOpen() const;
	int getTreasureValue() const;
	void setTreasureValue(int value);
};

