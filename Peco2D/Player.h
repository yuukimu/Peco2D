#pragma once
#include "Peco.h"

class Player
{
public:
	Player();
	~Player();
	void update();
	void draw() const;
	void move(int dx, int dy);
	Vec2 getPosition() const;
	void setDirection(int direction);
	void setIsGrounded(bool isGround);
	bool getIsGrounded() const;

private:
	Vec2 position;
	Texture positive;
	Texture reverse;
	int direction = 0; // 0: ‰EŒü‚«  1: ¶Œü‚«
	bool isGrounded;
};

