#include "ScreenDrawer.h"


SceneDrawer::SceneDrawer(std::shared_ptr<sf::RenderWindow> window)
	:window_(window), grassSprite_({})
{
	floorTile_ = textureLoader_.GetTexture("res/grass.png");
	floorTile_->setRepeated(true);
	grassSprite_.setTexture(*floorTile_);
	matrixDims_ = CalculateTileMatrixDims(*floorTile_);
}

void SceneDrawer::DrawGround()
{
	for (int i = 0; i < matrixDims_.x; i++)
	{
		for (int j = 0; j < matrixDims_.y; j++)
		{
			grassSprite_.setPosition(i * grassSprite_.getTexture()->getSize().x, j * grassSprite_.getTexture()->getSize().y);
			window_->draw(grassSprite_);
		}
	}
}

sf::Vector2i SceneDrawer::CalculateTileMatrixDims(const sf::Texture& floorTile) const
{
	sf::Vector2u textureSize{};

	textureSize = floorTile.getSize();

	auto windowSize = window_->getSize();

	auto columns = (windowSize.x / textureSize.x) + 1;
	auto rows = (windowSize.y / textureSize.y) + 1;

	return sf::Vector2i(columns, rows);
}
