#include "InputHandler.h"

ICommand::Ptr InputHandler::Handle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return std::make_unique<MoveCommand>();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return std::make_unique<MoveCommand>();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return std::make_unique<MoveCommand>();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return std::make_unique<MoveCommand>();
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		return std::make_unique<MoveCommand>();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		return std::make_unique<MoveCommand>();
	}*/
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		return std::make_unique<ICommand>

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		return std::make_unique<ICommand>
	}*/
}
