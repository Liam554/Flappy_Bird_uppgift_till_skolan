#include "AssetManger.hpp"

namespace Liam
{
	void AssetManger::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManger::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManger::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManger::GetFont(std::string name)
	{
		return this->GetFont(name);
	}
}