#pragma once

#include <cstdlib>
# include <Siv3D.hpp>
# include <HamFramework.hpp>

#define PLAYERH 120
#define PLAYERW 80

struct CommonData
{
	Font font{ 50 };
};

using Peco = SceneManager<String, CommonData>;