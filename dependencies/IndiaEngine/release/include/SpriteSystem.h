#pragma once
#include "Core.h"
#include "System.h"

namespace India {

	class India_EXPORT SpriteSystem : public System {
	public:
		~SpriteSystem() = default;
		/**
		Updates SpriteComponents in active scene.
		*/
		void Update(UpdateParameters& params) noexcept override;
	};

}