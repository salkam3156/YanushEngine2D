#pragma once
#include "Utils/WindowFactory.h"
#include "Utils/EntityFactory.h"
#include "Utils/AudioLoader.h"
#include "Interfaces/ICommand.h"
#include "Actions/InputHandler.h"
#include "stdafx.h"

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
	AudioLoader musicLoader_;
	sf::Listener listener_;
	InputHandler inputHandler_;
};