#include "Entity.h"

// Inherited via Drawable
namespace Objects
{
	Entity::Entity()
		: sprite_({}), texture_({})
	{
		float positionX = 0 + (std::rand() % (800 + 1));
		float positionY = 0 + (std::rand() % (600 + 1));

		sprite_.setPosition(positionX, positionY);

		texture_ = sf::Texture();
		if (!texture_.loadFromFile("res/miszcz.jpg"))
		{
			std::cerr << "Failed to load texture";
		}
		sprite_.setTexture(texture_);
		sprite_.scale(0.5, 0.5);
	}

	void Entity::Move()
	{
		sf::Vector2i movement = {};

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			movement.x -= 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			movement.x += 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			movement.y -= 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movement.y += 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sprite_.scale(1.1, 1.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sprite_.scale(0.7, 0.7);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			sprite_.rotate(0.7);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			sprite_.rotate(-0.7);
		}


		auto currPos = sprite_.getPosition();
		currPos.x += movement.x;
		currPos.y += movement.y;
		sprite_.setPosition(currPos);

	}


	void Entity::Draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(sprite_, states);
	}

	void Entity::Move(float x, float y)
	{
		auto currPos = sprite_.getPosition();
		currPos.x += x;
		currPos.y += y;
		sprite_.setPosition(currPos);
	}

	void Entity::MoveToMousePosition(sf::Vector2i position)
	{
		auto currPos = sprite_.getPosition();
		currPos.x = position.x;
		currPos.y = position.y;
		sprite_.setPosition(currPos);
	}
	void Entity::Scale(float delta)
	{
		auto test = 1 + delta / 10;
		sprite_.scale(1 + delta/10, 1 + delta / 10);
	}
}