#pragma once
#include "../stdafx.h"

class IEntity
{
public:
	enum class EntityType
	{
		PLAYER,
		ENEMY
	};

public:
	virtual void Move() = 0;
	virtual float Turn(sf::Vector2i position) = 0;
	virtual void Scale(float delta) = 0;
	virtual void Draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const = 0;
	virtual sf::Vector2f GetPosition() = 0;


public:
	IEntity(const IEntity& rhs) = delete;
	IEntity() {};
	~IEntity() {}
};