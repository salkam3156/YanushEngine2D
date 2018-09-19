#pragma once
#include "../stdafx.h"

namespace Graphics
{
	class WindowFactory
	{
	public:
		using WindowPtr = std::unique_ptr<sf::RenderWindow>;
		static WindowPtr GetWindow(std::string title)
		{
			sf::ContextSettings settings{
				settings.depthBits = 16,
				settings.antialiasingLevel = 4,
				settings.majorVersion = 4,
				settings.minorVersion = 3,
			};

			auto window = std::make_unique<sf::RenderWindow>(::sf::VideoMode(800, 600), title, (sf::Style::Close | sf::Style::Resize), settings);
			window->setFramerateLimit(120);
			window->setVerticalSyncEnabled(true);
			window->setKeyRepeatEnabled(true);
			window->setMouseCursorVisible(false);

			return window;
		}
	};

};