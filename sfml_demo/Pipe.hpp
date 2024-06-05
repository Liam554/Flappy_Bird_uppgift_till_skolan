#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Liam
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);

		void DrawPipes();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeStripes;
	};
}