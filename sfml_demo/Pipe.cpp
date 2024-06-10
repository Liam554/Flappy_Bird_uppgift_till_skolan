#include "Pipe.hpp"
#include <iostream>

namespace Liam
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}

	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);

		pipeStripes.push_back(sprite);
	}
	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, 0 - _pipeSpawnYOffset);

		pipeStripes.push_back(sprite);
	}
	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeStripes.push_back(sprite);
	}


	void Pipe::MovePipes(float dt)
	{
		for (unsigned short int i = 0; i < pipeStripes.size(); i++)
		{
			if (pipeStripes.at(i).getPosition().x < 0 - pipeStripes.at(i).getGlobalBounds().width)
			{
				pipeStripes.erase(pipeStripes.begin() + i);
			}

			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeStripes.at(i).move(-movement, 0);
			}
		}

		for (unsigned short int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}

			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;

				scoringPipes.at(i).move(-movement, 0);
			}
		}
	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeStripes.size(); i++)
		{
			_data->window.draw(pipeStripes.at(i));
		}
	}

	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite>& Pipe::GetSprites() const
	{
		return pipeStripes;
	}

	std::vector<sf::Sprite>& Pipe::GetScoringSprites() 
	{
		return scoringPipes;
	}

}