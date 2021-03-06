#include "Application.h"

Application::Application()
	: active_{ true }, clock_({})
{
	window_ = Graphics::WindowFactory::GetWindow("Main");
	entities_.emplace_back(Utils::EntityFactory::GetEntity(IEntity::EntityType::PLAYER));
	
	musicLoader_.LoadMusic("");
	musicLoader_.PlayMusic();
	listener_.setDirection(0,0,0);
	sceneDrawer_ = std::make_unique<SceneDrawer>(window_);
	view_.reset({ 0, 0, (float)window_->getSize().x, (float)window_->getSize().y });
}

bool Application::IsActive() const
{
	return active_;
}

void Application::Update()
{
	bool mouseInScreen = false;
	bool turn = false;
	auto testEnt = Utils::EntityFactory::GetEntity(IEntity::EntityType::PLAYER);

	while (active_)
	{
		if (clock_.getElapsedTime().asMilliseconds() > 16)
		{
			// handle events
			while (window_->pollEvent(event_))
			{
				if (event_.type == sf::Event::Closed)
				{
					active_ = false;
				}
				else if (event_.type == sf::Event::Resized)
				{
					// adjust the viewport when the window is resized
					glViewport(0, 0, event_.size.width, event_.size.height);
				}
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
				view_.move(entity->GetPosition() - view_.getCenter());
				if (mouseInScreen)
				{
					auto mousePos = sf::Mouse::getPosition(*window_);
					auto windowCenterCoords = sf::Vector2i{ (int)window_->getSize().x / (int)2 , (int)window_->getSize().y / (int)2 };
					auto mousePosFromCenter = mousePos - windowCenterCoords;
					entity->Turn(mousePosFromCenter);
				}

				if (auto command = inputHandler_.Handle())
				{
					command->Execute(*entity);
				}
				sceneDrawer_->DrawGround();
				window_->setView(view_);
				entity->Draw(*window_);

			}
			testEnt->Draw(*window_);
			window_->display();
			clock_.restart();
		}
		
	}
}
