#include "Player.h"

Player::Player()
{
	Player::position = Vec2(100, 640);
	Player::positive = Texture(L"Resource/img/player-sub.png");
	Player::reverse = Texture(L"Resource/img/player-sub-reverse.png");
}

Player::~Player()
{
}

void Player::update() {}

void Player::draw() const
{
	if (Player::direction == 0)
	{
		RectF(Player::position.x - 44, Player::position.y - 137, 88, 137)(Player::positive).draw();
	}
	else {
		RectF(Player::position.x - 44, Player::position.y - 137, 88, 137)(Player::reverse).draw();
	}
	
}

void Player::move(int dx, int dy)
{
	int tmpX = Player::position.x + dx;
	if (tmpX < 44)
	{
		Player::position.x = 44;
		return;
	} else if (tmpX > 640) {
		Player::position.x = 640;
		return;
	}
	//if (Player::position.x < 44 || Player::position.x >= 640)
	//{
	//	return;
	//}

	Player::position.x += dx;
	Player::position.y += dy;
}

Vec2 Player::getPosition() const
{
	return Player::position;
}

void Player::setDirection(int direction) {
	Player::direction = direction;
}