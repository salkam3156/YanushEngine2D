#include "Application.h"

int main()
{
	Application app;

	while (app.IsActive())
	{
		app.Update();
	}

	return 0;
}
