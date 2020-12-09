#pragma once

#include "System.h"
#include <vector>
#include <iostream>

namespace India {

	class India_EXPORT ActiveSceneSystem : public System {
	private:
		DrawingFacade& _drawing_facade;
		float _fadein_progress = 0;
		float _fadeout_progress = 0;
	public:
		ActiveSceneSystem(DrawingFacade& drawing_facade);
		~ActiveSceneSystem() = default;

		/**
		Calls scenemanager to returns vector with scenes that have an ActiveSceneComponent. 
		Loops through the provided vector, checks if the scene is permitted to be actived.
		Call SceneManager->SetActiveScene to toggle objects active.
		*/
		void Update(UpdateParameters& params) noexcept override;
	};

}