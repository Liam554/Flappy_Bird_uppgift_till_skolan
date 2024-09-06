#include "AssetManger.hpp"

namespace Liam
{
    	// Function to load a texture from a file and store it in the _textures map with a given name
	void AssetManger::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}
	// Function to retrieve a reference to a texture from the _textures map using its name
	sf::Texture& AssetManger::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}
    	// Function to load a font from a file and store it in the _fonts map with a given name
	void AssetManger::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}
    	// Function to retrieve a reference to a font from the _fonts map using its name
	sf::Font &AssetManger::GetFont(std::string name)
	{
		return this->GetFont(name);
	}
}
