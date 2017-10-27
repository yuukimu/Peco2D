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
	Single::player = Player();
}

void Single::update()
{
	Single::checkCollision();
	Single::receiveKeyEvent();
	if (!Single::player.getIsGrounded()) {
		Single::player.move(0, 2);
	}

	if (Single::player.getPosition().y >= 720) {
		changeScene(L"Title");
	}
}

void Single::draw() const
{
	Single::drawBlocks();
	Single::player.draw();
}

void Single::drawBlocks() const {
	for (size_t i = 0; i < Single::blocks.size(); i++) {
		if (Single::blocks[i].checkInRange(Single::startX)) {
			Single::blocks[i].draw(Single::startX);
		}
	}
}

void Single::receiveKeyEvent() {
	if (Single::checkInputFrame()) {
		if (Input::KeyRight.pressed) {
			Single::player.setDirection(0);
			if (!Single::player.getRightEnable()) {
				Single::inputFrame = INPUTFRAME;
				return;
			}
			if (Single::player.getPosition().x >= 640) {
				Single::startX++;
				Single::player.move(CHARDX, 0);
			} else {
				Single::player.move(CHARDX * 5, 0);
			}
			Single::inputFrame = INPUTFRAME;
		} else if (Input::KeyLeft.pressed) {
			Single::player.setDirection(1);
			if (!Single::player.getLeftEnable()) {
				Single::inputFrame = INPUTFRAME;
				return;
			}
			if (Single::startX == 0) {
				Single::player.move(-CHARDX * 5, 0);
			}
			if (Single::player.getPosition().x >= 44 && Single::startX > 0) {
				Single::startX--;
			}
			Single::inputFrame = INPUTFRAME;
		}
	}
}

void Single::checkCollision() {
	Vec2 pos = Single::player.getPosition();
	// âE
	int x = (pos.x + (Single::startX + 1) * 40) / 40;
	int y = (pos.y - 40) / 40;
	if (Single::mapData[y][x] == 0){
		Single::player.setRightEnable(true);
	} else {
		Single::player.setRightEnable(false);
	}

	// ç∂
	x = (pos.x + (Single::startX - 1) * 40) / 40;
	if (Single::mapData[y][x] == 0) {
		Single::player.setLeftEnable(true);
	} else {
		Single::player.setLeftEnable(false);
	}

	// â∫
	x = (pos.x + Single::startX * 40) / 40;
	y = pos.y / 40;
	if (Single::mapData[y][x] == 0) {
		Single::player.setIsGrounded(false);
	}
	else {
		Single::player.setIsGrounded(true);
	}
}

void Single::readMapCSV(String filename)
{
	const CSVReader csv(L"Resource/csv/stage2.csv");
	
	if (!csv) return;

	// CSVÇÃçsêî
	const int rowsCount = csv.rows;
	// CSVÇÃóÒêî
	const int columnCount = csv.columns(0);

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < columnCount; j++)
		{
			int val = csv.getOr<int32>(i, j, 0);
			Single::mapData[i][j] = val;
			if (val == 1)
			{
				Single::blocks.push_back(Block({ int(j), int(i) }));
			}
		}
	}
	return;
}

bool Single::checkInputFrame()
{
	if (Single::inputFrame == 0) {
		return true;
	}
	else {
		Single::inputFrame--;
		return false;
	}
}