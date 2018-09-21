#include "MoveCommand.h"

void MoveCommand::Execute(Objects::Entity& entity)
{
	entity.Move();
}
