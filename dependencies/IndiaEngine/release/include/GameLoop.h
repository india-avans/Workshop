#pragma once
#include "Core.h"
#include <functional>
#include <chrono>

namespace India {

	class GameLoop
	{
	public:
		GameLoop(std::function<void()> update, std::function<void()> render, int max_fps, bool condition = true) noexcept;
		~GameLoop();
		/**
		Initializes the taskloop
		*/
		void Start();
		/**
		Stops the taskloop
		*/
		void Stop() noexcept;

	private:
		std::function<void()> _update;
		std::function<void()> _render;
		int _max_fps;
		int _ticks;
		float _ms_per_frame;
		float _delta_time = 0;
		bool _condition;
		bool _is_started;

		std::chrono::high_resolution_clock::time_point _current_tick;
		std::chrono::high_resolution_clock::time_point _previous_tick;
	};
}