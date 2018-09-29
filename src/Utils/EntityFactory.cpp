#include "EntityFactory.h"

namespace Utils
{
	Objects::Entity::Ptr EntityFactory::GetEntity(IEntity::EntityType type)
	{
		return std::make_unique<Objects::Entity>(type);
	}
}

