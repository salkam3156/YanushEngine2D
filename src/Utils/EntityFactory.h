#pragma once
#include "../Objects/Entity.h"

namespace Utils
{
	class EntityFactory
	{
	public:
		static Objects::Entity::Ptr GetEntity(IEntity::EntityType type);
	};
}

