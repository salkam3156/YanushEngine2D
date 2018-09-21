#include "EntityFactory.h"

namespace Utils
{
	Objects::Entity::Ptr EntityFactory::GetEntity(Objects::EntityType type)
	{
		return std::make_unique<Objects::Entity>(type);
	}
}

