#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Liam
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

	};
}