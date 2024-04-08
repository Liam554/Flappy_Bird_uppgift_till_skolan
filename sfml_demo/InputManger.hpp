//pragma alla hpp filerna annars funkar inte coden :(
#pragma once

#include <SFML/Graphics.hpp>

namespace Liam
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}