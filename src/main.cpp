#include "stdafx.h"
#include "Application.h"
#include "Utils/AudioLoader.h"

int main()
{
	
	Application app;
	AudioLoader musicLoader;
	musicLoader.LoadMusic("res/spiewajacaKoza.wav");
	musicLoader.PlayMusic();

	while (app.IsActive())
	{
		app.Update();
	}

	return 0;
}