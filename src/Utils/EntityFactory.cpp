#include "EntityFactory.h"

namespace Utils
{
	
	Objects::Entity::Ptr EntityFactory::GetEntity()
	{
		return std::make_unique<Objects::Entity>();
	}
}

