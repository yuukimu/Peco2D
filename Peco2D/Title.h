#pragma once

#include "Peco.h"

class Title : public Peco::Scene
{
public:
	void init() override;
	void update() override;
	void draw() const override;
private:
	Texture bgImage;
	Rect startButton = Rect(588, 300, 104, 58);
	Rect conButton = Rect(588, 370, 104, 58);
};
