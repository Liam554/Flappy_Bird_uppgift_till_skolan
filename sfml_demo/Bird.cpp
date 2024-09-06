#include "Bird.hpp"


namespace Liam
{
	// Constructor for the Bird class, initializes bird's texture, position, and state
	Bird::Bird(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));

		_birdSprite.setTexture(_animationFrames.at(_animationIterator));

		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));
		_birdState = BIRD_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);

		_birdSprite.setOrigin(origin);

		_rotation = 0;
	}

	// Draw the bird sprite on the game window
	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}
	// Animate the bird by cycling through the animation frames based on time
	void Bird::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_birdSprite.setTexture(_animationFrames.at(_animationIterator));

			_clock.restart();
		}
	}
	// Update the bird's position and rotation based on its state (falling or flying)
	void Bird::Update(float dt)
	{
		if (BIRD_STATE_FALLING == _birdState)
		{
			_birdSprite.move(0, GRAVITY * dt);

			_rotation += ROTATION_SPEED * dt;

			if (_rotation > 25.0f)
			{
				_rotation = 25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}
		else if (BIRD_STATE_FLYING == _birdState)
		{
			_birdSprite.move(0, -FLYING_SPEED * dt);

			_rotation -= ROTATION_SPEED * dt;

			if (_rotation < -25.0f)  // Limit the bird's rotation to a minimum angle of -25 degrees
			{
				_rotation = 25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}
		// If the bird has been flying for longer than the allowed flying duration, switch to falling state
		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
		{
			_movementClock.restart();
			_birdState = BIRD_STATE_FALLING;
		}
	}
	// Handle the player's input to make the bird fly
	void Bird::Tap()
	{
		_movementClock.restart();
		_birdState = BIRD_STATE_FLYING;
	}
	// Return a constant reference to the bird's sprite (used for collision detection, etc.)
	const sf::Sprite& Bird::GetSprite() const
	{
		return _birdSprite;
	}

}
