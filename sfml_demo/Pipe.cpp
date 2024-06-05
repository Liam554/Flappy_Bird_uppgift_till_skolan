#include "Pipe.hpp"

namespace Liam
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{

	}

	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		pipeStripes.push_back(sprite);
	}
	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, 0);

		pipeStripes.push_back(sprite);
	}
	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeStripes.push_back(sprite);
	}
	void Pipe::MovePipes(float dt)
	{
		for (unsigned short int i = 0; i < pipeStripes.size(); i++)
		{
			sf::Vector2f position = pipeStripes.at(i).getPosition();
			float movement = PIPE_MOVEMENT_SPEED * dt;

			pipeStripes.at(i).move( -movement, 0);
		}
	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeStripes.size(); i++)
		{
			_data->window.draw(pipeStripes.at(i));
		}
	}
}