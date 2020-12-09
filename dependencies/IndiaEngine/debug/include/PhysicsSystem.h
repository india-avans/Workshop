#pragma once
#include "Core.h"
#include "System.h"

namespace India {

	class India_EXPORT PhysicsSystem : public System {
	public:
		~PhysicsSystem() = default;
		/**
		Updates the location of physicscomponents, accordingly to their properties
		*/
		void Update(UpdateParameters& params) noexcept override;
	};

}