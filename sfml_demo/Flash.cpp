#include "Flash.hpp"

namespace Liam
{
	// Constructor for the Flash class, initializes the flash effect with a reference to the game data
	Flash::Flash(GameDataRef data) : _data(data)
	{
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));

		_flashOn = true;
	}
	// Function to update the flash effect each frame based on delta time (dt)
	void Flash::Show(float dt)
	{
		if (_flashOn)
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_flashOn = false;
			}
			
			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else // If the flash is off, decrease the opacity of the rectangle
		{
			int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);

			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}
	// Draw the flash effect on the screen
	void Flash::Draw()
	{
		_data->window.draw(_shape);
	}
}
