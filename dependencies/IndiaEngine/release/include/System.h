#pragma once
#include "Core.h"
#include "SceneManager.h"
#include "Components.h"
#include "ManagerPool.h"

namespace India {

	struct UpdateParameters {
	public:
		UpdateParameters(float delta_time_ms, float scaled_delta_time_ms, SceneManager& scene_manager) 
			: scene_manager{ scene_manager }, delta_time_ms{ delta_time_ms }, scaled_delta_time_ms{scaled_delta_time_ms} {}
		float delta_time_ms;
		float scaled_delta_time_ms;
		SceneManager& scene_manager;
	};

	class India_EXPORT System {
	public:
		/**
		* Updates the game state with the logic of the concrete class.
		*/
		virtual void Update(UpdateParameters& params) = 0;
		virtual ~System() = default;
	};

}