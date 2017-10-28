#include "Block.h"

Block::Block()
{
}

Block::Block(int x, int y)
{
	Block::x = x;
	Block::y = y;
	Block::region = RectF(x*40, y*40, 40, 40);
}

Block::~Block()
{
}

void Block::update() {};

void Block::draw(int startX) const
{
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

int Block::checkCollision(RectF player, int startX) const {
	RectF tmp = Block::region.movedBy(-startX * 40, 0);
	if (tmp.intersects(player)) {
		if (tmp.x >= player.x) {
			// âE
			return 1;
		}
		else if (tmp.x + 40 >= player.x) {
			// ç∂
			return 3;
		}
	}
	return 0;
}
