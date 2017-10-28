#include "Grass.h"



Grass::Grass(){}

Grass::Grass(int x, int y) {
	Grass::x = x;
	Grass::y = y;
	Grass::region = RectF(x * 40, y * 40, 40, 40);
}

Grass::~Grass()
{
}

void Grass::draw(int startX) const {
	if (Grass::checkInRange(startX))
	{
		int tmpx = Grass::x * 40 - startX * 40;
		int tmpy = Grass::y * 40;
		Grass::region.movedBy(-startX * 40, 0).draw(Color(0,0,0,0));
		TextureAsset(L"grass").resize(40, 40).draw(tmpx, tmpy);
	}
}

bool Grass::checkInRange(int startX) const
{
	int diff = Grass::x - startX;
	if (diff < 32 && diff >= 0)
	{
		return true;
	}
	return false;
}