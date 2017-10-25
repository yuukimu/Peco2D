#include "Peco.h"
#include "Title.h"
#include "Single.h"

void Main()
{
	Peco manager;
	Window::Resize(1280, 720);
	manager.add<Title>(L"Title");
	manager.add<Single>(L"Single");
	//manager.add<Result>(L"Result");
	Window::SetTitle(L"PECO");
	while (System::Update())
	{
		manager.updateAndDraw();
	}
}
