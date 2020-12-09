#pragma once
#include "System.h"
#include "InputComponent.h"
#include "InputFacade.h"

namespace India {
	class India_EXPORT InputSystem : public System
	{
	private:
		InputFacade input_facade;
		void Update() noexcept;
	public:
		/**
		Updates objects with inputcomponent in active scene, callback occurs on each item in the vector
		*/
		void Update(UpdateParameters& params) noexcept;
		/**
		An event that occurs when key is released
		*/
		bool KeyReleased(std::string scanCode) const noexcept;
		/**
		An event that occurs on key press
		*/
		bool KeyPressed(std::string scanCode) const noexcept;		
		/**
		An event that occurs when key is fully pressed
		*/
		bool KeyDown(std::string scanCode) const noexcept;
		/**
		An event that occurs when a button (controller) is pressed.
		*/
		bool ButtonDown(std::string scanCode) const noexcept;
		InputSystem() noexcept;
		~InputSystem() = default;
	};
}
