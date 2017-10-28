#pragma once

#include "Peco.h"
class Grass
{
public:
	Grass();
	Grass(int x, int y);
	~Grass();
	void draw(int startX) const;
	bool checkInRange(int startX) const;

private:
	RectF region;
	int x;
	int y;
};

