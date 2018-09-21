#pragma once
#include "../Interfaces/ICommand.h"
#include "../Objects/Entity.h"

class MoveCommand : public ICommand
{
public:
	// Inherited via ICommand
	virtual void Execute(Objects::Entity& entity)  override;
};

