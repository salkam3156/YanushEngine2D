#pragma once
//#include "stdafx.h"
#include "../Interfaces/ICommand.h"
#include "../Actions/MoveCommand.h"

class InputHandler
{
public:
	ICommand::Ptr Handle();

private:
	ICommand::Ptr buttonLeft;
	ICommand::Ptr buttonRight;
	ICommand::Ptr buttonUp;
	ICommand::Ptr buttonDown;
	ICommand::Ptr mouseMoved;
};