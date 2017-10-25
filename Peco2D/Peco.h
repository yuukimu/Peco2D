#pragma once

# include <Siv3D.hpp>
# include <HamFramework.hpp>

struct CommonData
{
	Font font{ 50 };
};

using Peco = SceneManager<String, CommonData>;