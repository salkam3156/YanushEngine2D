#pragma once
#include "../stdafx.h"

class SceneDrawer
{
public:
	SceneDrawer() {}
	SceneDrawer(std::shared_ptr<sf::RenderWindow> window);
	void DrawGround();
private:
	sf::Vector2i CalculateTileMatrixDims(const sf::Texture& floorTile) const;

private:
	std::shared_ptr<sf::RenderWindow> window_;
	sf::Sprite grassSprite_;
	sf::Texture floorTile_;
	sf::Vector2i matrixDims_;
};
