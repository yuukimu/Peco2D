#pragma once
#include "Peco.h"
#include "Block.h"
#include "Player.h"

class Single : public Peco::Scene
{
	public:
		void init() override;
		void update() override;
		void draw() const override;
		void drawBlocks() const;
		void receiveKeyEvent(int status); // キー入力のイベント処理
		void checkIsGround();
		int checkCollision() const;

	private:
		void readMapCSV(String filename);
		bool checkInputFrame();

	private:
		int startX = 0;
		Player player;
		Array<Block> blocks;
		int inputFrame = 0;
};

