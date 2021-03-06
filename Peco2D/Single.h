#pragma once
#include "Peco.h"
#include "Block.h"
#include "Player.h"
#include "Bullet.h"
#include "Grass.h"

class Single : public Peco::Scene
{
	public:
		void init() override;
		void update() override;
		void draw() const override;
		void drawBlocks() const;
		void drawGrass() const;
		void receiveKeyEvent(); // キー入力のイベント処理
		void receiveAtackEvent();
		void receiveHideEvent();
		void receiveJumpEvent();
		void checkCollision();

	private:
		void readMapCSV(String filename);
		int getInputFrame() const;
		bool checkInputFrame();

	private:
		int startX = 0;
		Player player;
		Bullet bullet;
		int mapData[18][1000];
		Array<Block> blocks;
		Array<Grass> grasses;
		int inputFrame = 0;
};

