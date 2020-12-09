#pragma once
#include "Core.h"
#include "Component.h"

namespace India {

	class India_EXPORT PhysicsComponent : public Component {
	public:
		PhysicsComponent(const PhysicsComponent& other);
		PhysicsComponent() noexcept;
		PhysicsComponent(float mass) noexcept;
		~PhysicsComponent() override;
		
		float GetMass() const noexcept;
		void SetMass(float mass) noexcept;
	private:
		float _mass;
	};

}