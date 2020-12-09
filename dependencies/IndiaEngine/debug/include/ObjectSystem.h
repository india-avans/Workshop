#pragma once
#include "Core.h"
#include "System.h"

namespace India {

	class India_EXPORT ObjectSystem : public System {
	public:
		/**
		Calls the update method of every object
		*/
		void Update(UpdateParameters& params) noexcept override;
		~ObjectSystem() = default;
	};

}