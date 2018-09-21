#include "Application.h"

Application::Application()
	: active_{ true }, clock_({})
{
	window_ = Graphics::WindowFactory::GetWindow("Main");
	entities_.emplace_back(Utils::EntityFactory::GetEntity(Objects::EntityType::PLAYER));
	
	musicLoader_.LoadMusic("res/at.flac");
	musicLoader_.PlayMusic();
	listener_.setDirection(0,0,0);
}

bool Application::IsActive() const
{
	return active_;
}

void Application::Update()
{
	bool mouseInScreen = false;
	bool turn = false;

	while (active_)
	{
		if (clock_.getElapsedTime().asMilliseconds() > 16)
		{
			// handle events
			while (window_->pollEvent(event_))
			{
				if (event_.type == sf::Event::Closed)
				{
					// end the program
					active_ = false;
				}
				else if (event_.type == sf::Event::Resized)
				{
					// adjust the viewport when the window is resized
					glViewport(0, 0, event_.size.width, event_.size.height);
				}
				/*else if (event_.type == sf::Event::MouseWheelScrolled)
				{
					scale = event_.mouseWheelScroll.delta;
				}*/
				else if (event_.type == sf::Event::MouseLeft)
				{
					mouseInScreen = false;
				}
				else if (event_.type == sf::Event::MouseEntered)
				{
					mouseInScreen = true;
				}
				else if (event_.type == sf::Event::MouseMoved)
				{
					turn = true;
				}
			}
			// clear the buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (auto& entity : entities_)
			{
				if (mouseInScreen)
				{
					entity->Turn(sf::Mouse::getPosition(*window_));
				}

				if (auto command = inputHandler_.Handle())
				{
					command->Execute(*entity);
				}
				entity->Draw(*window_);
			}
			window_->display();
			clock_.restart();
		}
		
	}
}