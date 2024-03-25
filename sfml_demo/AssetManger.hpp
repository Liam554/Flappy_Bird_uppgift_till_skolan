#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Liam
{
	class AssetManger
	{
	public:
		AssetManger( ) { }
		~AssetManger() { }

		//Loads texture and the texture is a file so fileName
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		//same thing but for fonts
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}