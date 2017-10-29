#include "Bullet.h"

#define BULLETW 30
#define BULLETH 30

Bullet::Bullet()
{
}

Bullet::Bullet(int x, int y)
{
	Bullet::position = Vec2(x, y);
}

Bullet::~Bullet()
{
}

void Bullet::update() {
	if (Bullet::drawFlag)
	{
		Bullet::move(3, 0);
		Bullet::radian += 5;
	}
}

void Bullet::draw() const
{
	if (Bullet::drawFlag)
	{
		RectF(Bullet::position.x - BULLETW / 2, Bullet::position.y - BULLETH, BULLETW, BULLETH).rotated(Radians(Bullet::radian))(TextureAsset(L"bullet")).draw();
	}
}

void Bullet::move(int dx, int dy) {
	Bullet:: position.x += dx;
	Bullet::position.y += dy;
}

void Bullet::setPositon(double x, double y) {
	Bullet::position = Vec2(x, y);
}

void Bullet::setRadian(double radian) {
	Bullet::radian = radian;
}

double Bullet::getRadian() const {
	return Bullet::radian;
}

void Bullet::setDrawFlag(bool flag) {
	Bullet::drawFlag = flag;
}