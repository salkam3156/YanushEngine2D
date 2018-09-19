#pragma once
#include "stdafx.h"
#include "Utils/WindowFactory.h"
#include "Utils/EntityFactory.h"

class Application
{
public:
	Application();
	bool IsActive() const;
	void Update();
private:
	bool active_;
	Graphics::WindowFactory::WindowPtr window_;
	std::vector<Objects::Entity::Ptr> entities_;
	sf::Event event_;
	sf::Clock clock_;
	sf::Mouse mouse_;
};