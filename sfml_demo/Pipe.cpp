#include "Pipe.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>


namespace Liam
{
	// Constructor for the Pipe class, initializes game data and sets the land height for pipe spawning.
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = this->_data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}
    	// Spawns a bottom pipe at the right side of the window with a random vertical offset.
	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}
	// Spawns a top pipe at the right side of the window with a random vertical offset.
	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}
	// Spawns an invisible pipe for collision detection purposes (e.g., scoring).
	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}
	// Moves the pipes from right to left across the screen, and removes them if they go off-screen.
	void Pipe::MovePipes(float dt)
	{
		for (int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getLocalBounds().width)
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else
			{
				sf::Vector2f position = pipeSprites.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);
			}
		}
	}
	// Draws all the pipe sprites on the screen.
	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			this->_data->window.draw(pipeSprites.at(i));
		}
	}
	// Generates a random vertical offset for the pipes to create variation in their heights.
	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}
	// Returns the vector of pipe sprites for collision detection and other purposes.
	const std::vector<sf::Sprite>& Pipe::GetSprites() const
	{
		return pipeSprites;
	}
}
