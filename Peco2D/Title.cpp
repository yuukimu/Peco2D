#include "Title.h"

void Title::init()
{
	Title::bgImage = Texture(L"Resource/img/Title.png");
	TextureAsset::Register(L"start-btn", L"Resource/img/StartBtn.png");
	GUIAsset::Register(L"title_menu", GUIStyle::Default);
}

void Title::update()
{
	if (Title::startButton.leftPressed)
	{
		changeScene(L"Single");
	}
}

void Title::draw() const
{
	Title::bgImage.draw();
	Title::startButton(TextureAsset(L"start-btn")).draw();
	Title::conButton.draw(Palette::Orange);
}
