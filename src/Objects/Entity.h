#pragma once
#include "../stdafx.h"


namespace Objects
{
	enum class EntityType
	{
		PLAYER,
		ENEMY
	};
	
	class Entity
	{
	public:
		//TODO: flyweight pattern for texture reusal
		Entity(const Entity& rhs) = delete;

		using Ptr = std::unique_ptr<Entity>;

		Entity(EntityType type);

		void Move();
		void Turn(sf::Vector2i position);

		void Scale(float delta);
		// Inherited via Drawable
		void Draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;
		sf::Vector2f GetPosition();

	private:
		float CalculateRotationToMouse(const sf::Vector2i& mousePosition);
		sf::Sprite sprite_;
		sf::Texture texture_;
		bool scale_;

	};
}
