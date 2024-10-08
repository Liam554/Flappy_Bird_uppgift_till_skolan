#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace Liam
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}
//Init function to initialize game resources and state
	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);


		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_score = 0;


		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			land->MoveLand(dt);
			bird->Animate(dt);

		}
	        // If the game is in progress, update pipes, check for collisions, and handle game-over state
		if (GameStates::ePlaying == _gameState)
		{
			pipe->MovePipes(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				pipe->RandomisePipeOffset();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();

				clock.restart();
			}
			bird->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();

			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collition.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}

			std::vector<sf::Sprite> pipeStripes = pipe->GetSprites();

			for (int i = 0; i < pipeStripes.size(); i++)
			{
				if (collition.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeStripes.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}

		}

		if (GameStates::eGameOver == _gameState)
		{
			flash->Show( dt);
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();

		flash->Draw();

		_data->window.display();
	}
}
