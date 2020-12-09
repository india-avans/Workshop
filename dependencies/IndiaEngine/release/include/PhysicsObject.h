#pragma once
#include "Core.h"
#include "GameObject.h"

namespace India {
	struct India_EXPORT PhysicsObjectData : GameObjectData {
	public:
		PhysicsObjectData(const GameObjectData& data, float mass) noexcept;
		float mass;
	};

	class India_EXPORT PhysicsObject : public GameObject {
	public:
		PhysicsObject(const PhysicsObject& other);
		PhysicsObject(const PhysicsObjectData& data) noexcept;
		virtual ~PhysicsObject() = 0;
	};

}
