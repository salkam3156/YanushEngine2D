#include "Application.h"

Application::Application()
	: active_{ true }, clock_({})
{
	window_ = Graphics::WindowFactory::GetWindow("Main");
	entities_.emplace_back(Utils::EntityFactory::GetEntity());
}

bool Application::IsActive() const
{
	return active_;
}

void Application::Update()
{
	
	/*sf::Shader shader;
	if (!shader.loadFromFile("res/vertex.shader", "res/fragment.shader"))
	{
		std::cout << "Shader could not be loaded" << std::endl;
	}
	auto glVersion = glGetString(GL_VERSION);

	auto shaderAvailable = sf::Shader::isAvailable();*/
	int scale = 0;

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
				else if (event_.type == sf::Event::MouseWheelScrolled)
				{
					scale = event_.mouseWheelScroll.delta;
				}
			}

			// clear the buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// draw...

			// end the current frame (internally swaps the front and back buffers)

			for (auto& entity : entities_)
			{
				entity->MoveToMousePosition(mouse_.getPosition(*window_));
				entity->Move();
				if (scale != 0)
				{
					entity->Scale(scale);
					scale = 0;
				}
				entity->Draw(*window_);
			}
			window_->display();
			clock_.restart();
		}
		
	}
}
