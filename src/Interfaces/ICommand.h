#pragma once
#include "../stdafx.h"
#include "../Objects/Entity.h"

class ICommand
{
public:
	using Ptr = std::unique_ptr<ICommand>;

	virtual ~ICommand() {}
	virtual void Execute(Objects::Entity& entity) = 0;
};
