#include "TextureLoader.h"

sf::Texture TextureLoader::GetTexture(std::string textureName)
{
	sf::Texture texture;
	texture.loadFromFile(textureName);

	return texture;
}
