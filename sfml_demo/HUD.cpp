#include "HUD.hpp"
#include <string>

namespace Liam
{
	// Constructor to initialize the HUD with score display settings.
	HUD::HUD(GameDataRef data) 
	{
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));

		_scoreText.setString("0");

		_scoreText.setCharacterSize(128);

		_scoreText.setFillColor(sf::Color::White);

		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

		_scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 5);
	}
	// Draws the HUD elements to the window.
	void HUD::Draw()
	{
		_data->window.draw(_scoreText);
	}
    	// Updates the score displayed on the HUD.
	void HUD::UpdateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	}


}
