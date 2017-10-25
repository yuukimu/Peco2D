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

	private:
		void readMapCSV(String filename);
		bool checkInputFrame();

	private:
		int startX = 0;
		Player player;
		Array<Block> blocks;
		int inputFrame = 0;
};

