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

bool Block::checkIntersects(Vec2 pos, int startX) const {
	return  Block::region.movedBy(-startX * 40, 0).intersects(pos ) && Block::region.y == pos.y;
}

int Block::checkCollision(Vec2 pos, int startX) const {
	RectF tmp = Block::region.movedBy(-startX * 40, 0);
	// â∫
	if (tmp.top.intersects(pos)) {
		return 8;
	}
	// è„
	/*if (Block::region.intersects(pos) && Block::region.y + 40 == pos.y - PLAYERH) {
		return 1;
	}*/
	//pos.x += PLAYERW / 2;
	//pos.y -= 1;
	// âE
	if ((tmp.left.intersects(pos))) {
		return 2;
	}
	// ç∂
	if (tmp.right.intersects(pos)) {
		return 4;
	}
	return 0;
}