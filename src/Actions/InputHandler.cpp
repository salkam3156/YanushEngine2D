#include "InputHandler.h"

ICommand::Ptr InputHandler::Handle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return std::make_unique<MoveCommand>();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return std::make_unique<MoveCommand>();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return std::make_unique<MoveCommand>();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return std::make_unique<MoveCommand>();
	}
	else
	{
		return nullptr;
	}
}
