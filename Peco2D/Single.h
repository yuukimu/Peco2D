#pragma once
#include "Peco.h"
#include "Block.h"
#include "Player.h"
#include "Bullet.h"

class Single : public Peco::Scene
{
	public:
		void init() override;
		void update() override;
		void draw() const override;
		void drawBlocks() const;
		void receiveKeyEvent(); // �L�[���͂̃C�x���g����
		void receiveAtackEvent();
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
		int inputFrame = 0;
};

