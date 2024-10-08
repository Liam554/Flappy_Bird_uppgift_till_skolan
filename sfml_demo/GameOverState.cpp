#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"

namespace Liam
{
	    // Constructor for GameOverState, initializing the game data reference
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

    // Initialize the game over state by loading textures and setting up UI elements
	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);


		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_background.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_background.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2));
		_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2));
		_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2));

	}

    // Handle player inputs, such as retry button click or window close event
	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}
	    // Update function, left empty as there is no logic to update in the game over state
	void GameOverState::Update(float dt)
	{

	}
    // Draw the game over screen elements (background, container, retry button) on the window
	void GameOverState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);

		_data->window.display();
	}
}
