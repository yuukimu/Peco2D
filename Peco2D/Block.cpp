#include "Block.h"

Block::Block()
{
}

Block::Block(int x, int y)
{
	Block::x = x;
	Block::y = y;
	int tx = x % 32;
	Block::region = RectF(x*40, y*40, 40, 40);
}

Block::~Block()
{
}

void Block::update() {};

void Block::draw(int startX) const
{
	int dx = startX % 32;
	Block::region.movedBy(-startX*40,0)(TextureAsset(L"block")).draw();
}

bool Block::checkInRange(int startX) const
{
	int diff = Block::x - startX;
	if (diff < 32 && diff >= 0)
	{
		return true;
	}
	return false;
}