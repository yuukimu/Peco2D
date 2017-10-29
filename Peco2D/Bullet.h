#pragma once

#include "Peco.h"

class Bullet
{
public:
	Bullet();
	Bullet(int x, int y);
	~Bullet();
	void update();
	void draw() const;
	void move(int dx, int dy);
	void setPositon(double x, double y);
	Vec2 getPosition() const;
	void setRadian(double radian);
	double getRadian() const;
	void setDrawFlag(bool flag);

private:
	Vec2 position;
	double radian = -5;
	bool drawFlag = false;
};

