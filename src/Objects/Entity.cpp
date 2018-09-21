#define _USE_MATH_DEFINES
#include "Entity.h"
#include <math.h>


// Inherited via Drawable
namespace Objects
{
	Entity::Entity(EntityType type)
		: sprite_({}), texture_({})
	{
		float positionX = 0 + (std::rand() % (800 + 1));
		float positionY = 0 + (std::rand() % (600 + 1));

		sprite_.setPosition(positionX, positionY);

		texture_ = sf::Texture();
		if (!texture_.loadFromFile("res/soljah.png"))
		{
			std::cerr << "Failed to load texture";
		}
		sprite_.setTexture(texture_);
		sprite_.scale(0.5, 0.5);

		auto bounds = sprite_.getLocalBounds();
		sprite_.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
	}

	void Entity::Move()
	{
		sf::Vector2i movement{};

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			movement.x -= 7;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			movement.x += 7;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			movement.y -= 7;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movement.y += 7;
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

	float Entity::CalculateRotationToMouse(const sf::Vector2i& mousePosition)
	{
		sf::Vector2f curPos = sprite_.getPosition();

		float dx = curPos.x - mousePosition.x;
		float dy = curPos.y - mousePosition.y;

		float rotation = ((atan2f(dy, dx)) * 180 / M_PI) + 180;

		return rotation ;
	}

	void Entity::Turn(sf::Vector2i position)
	{
		sprite_.setRotation(CalculateRotationToMouse(position));
	}
	void Entity::Scale(float delta)
	{
		sprite_.scale(1 + delta/10, 1 + delta / 10);
	}
}