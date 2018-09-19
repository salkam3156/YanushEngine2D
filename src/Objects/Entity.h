#pragma once
#include "../stdafx.h"

namespace Objects
{
	enum class EntityType : std::uint8_t
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

		Entity();

		void Move();
		void Move(float x, float y);
		void MoveToMousePosition(sf::Vector2i position);

		void Scale(float delta);
		// Inherited via Drawable
		void Draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;

	private:
		sf::Sprite sprite_;
		sf::Texture texture_;
		bool scale_;

	};
}