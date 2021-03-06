#include "Single.h"

#define MAPROWS 18
#define MAPCOLS 64
#define INPUTFRAME 6
#define CHARDX 5

void Single::init()
{
	Graphics::SetBackground(Palette::Aliceblue);
	Single::readMapCSV(L"stage1");
	TextureAsset::Register(L"block", L"Resource/img/block.png");
	TextureAsset::Register(L"bullet", L"Resource/img/bullet.png");
	TextureAsset::Register(L"grass", L"Resource/img/grass2.png");
	Single::player = Player();
	Single::bullet = Bullet();
}

void Single::update()
{
	Single::checkCollision();
	Single::receiveHideEvent();
	if (!Single::player.getIsHiden())
	{
		Single::receiveKeyEvent();
		Single::receiveJumpEvent();
		Single::receiveAtackEvent();
	}
	Single::player.update();
	Single::bullet.update();
	if (Single::player.getPosition().y >= 720) {
		changeScene(L"Title");
	}
}

void Single::draw() const
{
	Single::drawBlocks();
	Single::drawGrass();
	Single::player.draw();
	Single::bullet.draw();
}

void Single::drawBlocks() const {
	for (size_t i = 0; i < Single::blocks.size(); i++) {
		if (Single::blocks[i].checkInRange(Single::startX)) {
			Single::blocks[i].draw(Single::startX);
		}
	}
}

void Single::drawGrass() const {
	size_t len = Single::grasses.size();
	for (size_t i = 0; i < len; i++) {
		Single::grasses[i].draw(Single::startX);
	}
}

void Single::receiveKeyEvent() {
	if (Single::checkInputFrame()) {
		if (Input::KeyRight.pressed) {
			Single::player.setDirection(0);
			if (!Single::player.getRightEnable()) {
				Single::inputFrame = Single::getInputFrame();
				return;
			}
			if (Single::player.getPosition().x >= 640) {
				Single::startX++;
			}
			Single::player.move(CHARDX, 0);
			Single::inputFrame = Single::getInputFrame();
		} else if (Input::KeyLeft.pressed) {
			Single::player.setDirection(1);
			if (!Single::player.getLeftEnable()) {
				Single::inputFrame = Single::getInputFrame();
				return;
			}
			if (Single::startX == 0) {
				Single::player.move(-CHARDX, 0);
			}
			if (Single::player.getPosition().x >= 44 && Single::startX > 0) {
				Single::startX--;
			}
			Single::inputFrame = Single::getInputFrame();
		}
	}
}

void Single::receiveAtackEvent() {
	if (Input::KeySpace.clicked)
	{
		Vec2 pos = Single::player.getPosition();
		Single::bullet.setPositon(pos.x + PLAYERW * 0.45, pos.y - PLAYERH *0.5);
		Single::bullet.setDrawFlag(true);
	}
}

void Single::receiveHideEvent() {
	if (Input::KeyDown.clicked) {
		if (Single::player.getIsHiden()) {
			Single::player.setIsHiden(false);
			return;
		}
		Vec2 pos = Single::player.getPosition();
		int x = ((int)pos.x + Single::startX * 40) / 40;
		int y = ((int)pos.y - 40) / 40;
		if (Single::mapData[y][x] == 2) {
			Single::player.setIsHiden(true);
		}
	}
}

void Single::receiveJumpEvent() {
	if (Input::KeyUp.clicked) {
		if (Single::player.getJumpFrame() == 0 && Single::player.getIsGrounded()) {
			Single::player.setJumpFrame(50);
		}
	}
}

void Single::checkCollision() {
	Vec2 pos = Single::player.getPosition();
	// 右
	int x = ((int)pos.x + (Single::startX + 1) * 40) / 40;
	int y = ((int)pos.y - 40) / 40;
	if (Single::mapData[y][x] == 1 || Single::mapData[y - 1][x] == 1 || Single::mapData[y - 2][x] == 1) {
		Single::player.setRightEnable(false);
	}
	else {
		Single::player.setRightEnable(true);
	}

	// 左
	x = ((int)pos.x + (Single::startX - 1) * 40) / 40;
	if (Single::mapData[y][x] == 1 || Single::mapData[y - 1][x] == 1 || Single::mapData[y - 2][x] == 1) {
		Single::player.setLeftEnable(false);
	}
	else {
		Single::player.setLeftEnable(true);
	}

	// 下
	x = ((int)pos.x + Single::startX * 40) / 40;
	y = (int)pos.y / 40;
	if (Single::mapData[y][x] == 1) {
		Single::player.setIsGrounded(true);
	} else {
		Single::player.setIsGrounded(false);
	}
	/*if (Single::mapData[y][x] == 0) {
		Single::player.setIsGrounded(false);
	} else {
		Single::player.setIsGrounded(true);
	}*/
}

void Single::readMapCSV(String filename)
{
	const CSVReader csv(L"Resource/csv/stage2.csv");
	
	if (!csv) return;

	// CSVの行数
	const size_t rowsCount = csv.rows;
	// CSVの列数
	const size_t columnCount = csv.columns(0);

	for (size_t i = 0; i < rowsCount; i++) {
		for (size_t j = 0; j < columnCount; j++) {
			int val = csv.getOr<int32>(i, j, 0);
			Single::mapData[i][j] = val;
			if (val == 1) {
				Single::blocks.push_back(Block({ int(j), int(i) }));
			} else if (val == 2) {
				Single::grasses.push_back(Grass((int)j, (int)i));
			}
		}
	}
	return;
}

int Single::getInputFrame() const {
	if (Single::startX == 0) {
		return INPUTFRAME / 6;
	} else {
		return INPUTFRAME;
	}
}

bool Single::checkInputFrame()
{
	if (Single::inputFrame == 0) {
		return true;
	} else {
		Single::inputFrame--;
		return false;
	}
}