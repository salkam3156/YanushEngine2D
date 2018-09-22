#pragma once
#include "../stdafx.h"

class TextureLoader
{
public:
	std::shared_ptr<sf::Texture> GetTexture(std::string textureName);

private:
	std::map<std::string/*texture path*/, std::shared_ptr<sf::Texture>> textureMap_;
};
