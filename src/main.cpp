#include "stdafx.h"
#include "Application.h"


int main(int argc, char* args[])
{
	Application app;

	while (app.IsActive())
	{
		app.Update();
	}

	return 0;
}