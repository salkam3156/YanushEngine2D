#include "ScreenDrawer.h"
#include "../Utils/TextureLoader.h"

SceneDrawer::SceneDrawer(std::shared_ptr<sf::RenderWindow> window)
	:window_(window), grassSprite_({})
{
	floorTile_ = TextureLoader::GetTexture("res/grass.png");
	//floorTile_.generateMipmap();
	floorTile_.setRepeated(true);
	grassSprite_.setTexture(floorTile_);
	matrixDims_ = CalculateTileMatrixDims(floorTile_);
}

void SceneDrawer::DrawGround()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			grassSprite_.setPosition(i * grassSprite_.getTexture()->getSize().x, j * grassSprite_.getTexture()->getSize().y);
			window_->draw(grassSprite_);
		}
	}
}

sf::Vector2i SceneDrawer::CalculateTileMatrixDims(const sf::Texture& floorTile) const
{
	auto textureName = "res/grass";
	sf::Vector2u textureSize{};

	textureSize = floorTile.getSize();

	auto windowSize = window_->getSize();

	auto columns = windowSize.x / textureSize.x;
	auto rows = windowSize.y / textureSize.y;

	
	return sf::Vector2i(columns, rows);
}
