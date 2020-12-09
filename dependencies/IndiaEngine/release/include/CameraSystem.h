#pragma once
#include "System.h"
#include <vector>
#include <iostream>

namespace India {

	class India_EXPORT CameraSystem : public System {
	public:
		CameraSystem(DrawingFacade& drawing_facade) noexcept;
		~CameraSystem() = default;
		void Update(UpdateParameters& params) noexcept;
	private:
		DrawingFacade& _drawing_facade;
	};

}