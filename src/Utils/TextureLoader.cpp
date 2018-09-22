#include "TextureLoader.h"

std::shared_ptr<sf::Texture> TextureLoader::GetTexture(std::string textureName)
{
	std::shared_ptr<sf::Texture> existingTexture{nullptr};
	try
	{
		existingTexture = textureMap_.at(textureName);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << "Loading texture: " << textureName << std::endl;
	}

	if (existingTexture)
	{
		existingTexture->loadFromFile(textureName);
		return existingTexture;
	}
	else
	{
		textureMap_.emplace(textureName, std::make_shared<sf::Texture>());
		auto& insertedTexture = textureMap_.at(textureName);
		insertedTexture->loadFromFile(textureName);

		return insertedTexture;
	}
}
