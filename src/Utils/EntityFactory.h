#pragma once

#pragma once
#include "../stdafx.h"
#include "../Objects/Entity.h"

namespace Utils
{
	class EntityFactory
	{
	public:
		static Objects::Entity::Ptr GetEntity(Objects::EntityType type);
	};
}

