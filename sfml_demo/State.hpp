//pragma alla hpp filerna annars funkar inte coden :(
#pragma once

namespace Liam
{
	// This is part of the State design pattern, which allows for different game states (e.g., Main Menu, Game Over, Playing).
	class State
	{
	public:
		virtual void Init() = 0;

		virtual void HandleInput( ) = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw( float dt) = 0;

		virtual void Pause( ) { }
		virtual void Resume( ) { }
	};
}
