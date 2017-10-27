#include "Player.h"

Player::Player()
{
	Player::position = Vec2(100, 140);
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
		RectF(Player::position.x - PLAYERW/2, Player::position.y - PLAYERH, PLAYERW, PLAYERH)(Player::positive).draw();
	}
	else {
		RectF(Player::position.x - PLAYERW/2, Player::position.y - PLAYERH, PLAYERW, PLAYERH)(Player::reverse).draw();
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

void Player::setIsGrounded(bool isGround) {
	Player::isGrounded = isGround;
}

bool Player::getIsGrounded() const {
	return Player::isGrounded;
}