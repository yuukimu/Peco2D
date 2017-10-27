#pragma once

#include <cstdlib>
# include <Siv3D.hpp>
# include <HamFramework.hpp>

#define PLAYERH 137
#define PLAYERW 88

struct CommonData
{
	Font font{ 50 };
};

using Peco = SceneManager<String, CommonData>;