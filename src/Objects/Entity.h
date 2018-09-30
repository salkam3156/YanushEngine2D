#pragma once
#include "../stdafx.h"
#include "../Interfaces/IEntity.h"


namespace Objects
{
	
	
	class Entity : public IEntity
	{
	public:
		//TODO: flyweight pattern for texture reusal
		Entity(const Entity& rhs) = delete;

		using Ptr = std::unique_ptr<Entity>;

		Entity(EntityType type);

		void Move() override;
		float Turn(sf::Vector2i position) override;

		void Scale(float delta) override;
		// Inherited via Drawable
		void Draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const override;
		sf::Vector2f GetPosition() override;

	private:
		float CalculateRotationToMouse(const sf::Vector2i& mousePosition);
		sf::Sprite sprite_;
		sf::Texture texture_;
		bool scale_;

	};
}
