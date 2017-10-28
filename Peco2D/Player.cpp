#include "Player.h"

Player::Player()
{
	Player::position = Vec2(100, 640);
	Player::positive = Texture(L"Resource/img/PecoBear1.png");
	Player::reverse = Texture(L"Resource/img/PecoBear1-reverse.png");
	Player::hide = Texture(L"Resource/img/player-hide.png");
	Player::rightEnable = true;
	Player::leftEnable = true;
	Player::isHiden = false;
}

Player::~Player()
{
}

void Player::update() {
	if (!Player::isGrounded)
	{
		Player::move(0, 2);
	}
}

void Player::draw() const
{
	if (Player::isHiden) {
		RectF(Player::position.x - PLAYERW / 2, Player::position.y - PLAYERH, PLAYERW, PLAYERH)(Player::hide).draw();
		return;
	}
	if (Player::direction == 0) {
		RectF(Player::position.x - PLAYERW/2, Player::position.y - PLAYERH, PLAYERW, PLAYERH)(Player::positive).draw();
	} else {
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
	Player::position.x += dx;
	Player::position.y += dy;
}

void Player::setPosition(int x, int y) {
	Player::position.x = x;
	Player::position.y = y;
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

void Player::setRightEnable(bool enable) {
	Player::rightEnable = enable;
}

bool Player::getRightEnable() const {
	return Player::rightEnable;
}

void Player::setLeftEnable(bool enable) {
	Player::leftEnable = enable;
}

bool Player::getLeftEnable() const {
	return Player::leftEnable;
}

void Player::setIsHiden(bool flag) {
	Player::isHiden = flag;
}

bool Player::getIsHiden() const {
	return Player::isHiden;
}