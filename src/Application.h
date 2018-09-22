#pragma once
#include "Utils/WindowFactory.h"
#include "Utils/EntityFactory.h"
#include "Utils/AudioLoader.h"
#include "Interfaces/ICommand.h"
#include "Scene/ScreenDrawer.h"
#include "Actions/InputHandler.h"

class Application
{
public:
	Application();
	bool IsActive() const;
	void Update();

private:
	bool active_;
	std::shared_ptr<sf::RenderWindow> window_;
	std::vector<Objects::Entity::Ptr> entities_;
	sf::Event event_;
	sf::Clock clock_;
	AudioLoader musicLoader_;
	sf::Listener listener_;
	InputHandler inputHandler_;
	std::unique_ptr<SceneDrawer> sceneDrawer_;

};