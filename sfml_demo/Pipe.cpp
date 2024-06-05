#include "Pipe.hpp"

namespace Liam
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{

	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeStripes.size(); i++)
		{
			_data->window.draw(pipeStripes.at(i));
		}
	}
}