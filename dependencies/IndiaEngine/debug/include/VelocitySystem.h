#pragma once
#include "Core.h"
#include "System.h"

namespace India {

	class India_EXPORT VelocitySystem : public System {
	public:
		~VelocitySystem() = default;
		/**
		Iterates through objects in active scene to update them accordingly to their velocity properties & provided delta_time.
		*/
		void Update(UpdateParameters& params) noexcept override;
	};

}