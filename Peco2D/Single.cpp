#include "Single.h"

#define MAPROWS 18
#define MAPCOLS 64
#define INPUTFRAME 6
#define CHARDX 4

void Single::init()
{
	Graphics::SetBackground(Palette::Aliceblue);
	Single::readMapCSV(L"stage1");
	TextureAsset::Register(L"block", L"Resource/img/block.png");
	Single::player = Player();
}

void Single::update()
{
	if (Single::checkInputFrame())
	{
		if (Input::KeyRight.pressed)
		{
			Single::player.setDirection(0);
			if (Single::player.getPosition().x >= 640)
			{
				Single::startX++;
				Single::player.move(CHARDX, 0);
			} else {
				Single::player.move(CHARDX * 5, 0);
			}
			Single::inputFrame = INPUTFRAME;
		}
		else if (Input::KeyLeft.pressed) {
			Single::player.setDirection(1);
			if (Single::startX == 0) {
				Single::player.move(-CHARDX*5, 0);
			}
			if (Single::player.getPosition().x >= 44 && Single::startX > 0)
			{
				Single::startX--;
			}
			Single::inputFrame = INPUTFRAME;
		}
	}
}

void Single::draw() const
{
	for (size_t i = 0; i < Single::blocks.size(); i++)
	{
		if (Single::blocks[i].checkInRange(Single::startX))
		{
			Single::blocks[i].draw(Single::startX);
		}
	}
	Single::player.draw();
}

void Single::readMapCSV(String filename)
{
	const CSVReader csv(L"Resource/csv/stage2.csv");
	
	if (!csv) return;

	// CSV‚Ìs”
	const int rowsCount = csv.rows;
	// CSV‚Ì—ñ”
	const int columnCount = csv.columns(0);

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < columnCount; j++)
		{
			int val = csv.getOr<int32>(i, j, 0);
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