#pragma once
#include "Systems.h"
#include "Managers.h"
#include "DrawingFacade.h"
#include <GameLoop.h>

#include<memory>

namespace India {

	class India_EXPORT IndiaEngine {
	private:
		/**
		Enemyts the provided scene(s) and enter the task loop.
		*/
		void Enemyt(std::vector<std::unique_ptr<Scene>>& scenes, int index = 0) noexcept;

		void Update(float delta_time, float delta_time_scaled, GameLoop& loop) noexcept;
		void Render(float delta_time, float delta_time_scaled) noexcept;

		/**
		Initializes the engine, game systems and graphic systems.
		*/
		void Initialize(const std::string& title) noexcept;
		/**
		Lets the engine interact with networking.
		*/
		void PollNetwork() noexcept;
		/**
		Event that occurs when scene changes.
		*/
		void OnSceneChanged() noexcept;

		std::unique_ptr<InputFacade> _input_facade;
		std::unique_ptr<DrawingFacade> _drawing_facade;
		std::vector<std::unique_ptr<System>> _game_systems;
		std::vector<std::unique_ptr<System>> _graphics_systems;
	public:
		IndiaEngine(const std::string& title, std::vector<std::unique_ptr<Scene>>& scenes, int index = 0) noexcept;
		~IndiaEngine();
	};

	IndiaEngine& Create();
}