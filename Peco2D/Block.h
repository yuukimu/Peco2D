#pragma once
#include "Peco.h"

class Block
{
public:
	Block();
	Block(int x, int y);
	~Block();
	void update();
	void draw(int startX) const;
	bool checkInRange(int startX) const;

private:
	RectF region;
	int x;
	int y;
};

