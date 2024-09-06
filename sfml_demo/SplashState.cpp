#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Liam
{
	// Constructor for the SplashState, which takes a reference to the game data.
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}
    	// Initializes the splash screen by loading the background texture.
	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}
	// Handles user input for the splash screen state.
	void SplashState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}
    	// Updates the splash screen. Transitions to the main menu after a certain amount of time.
	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
    	// Draws the splash screen background.
	void SplashState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}
