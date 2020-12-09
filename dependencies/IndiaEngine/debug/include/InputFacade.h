#pragma once
#include "InputKeyTranslatorSDL.h"
#include <map>
#include <vector>
#include <functional>
#include "InputEvent.h"

namespace India {
	class InputFacade {
	private:
		InputKeyTranslatorSDL input_key_translator;
	public:
		/**
		Facade method for KeyReleased to hide SDL
		*/
		bool KeyReleased(std::string scanCode) const noexcept;
		/**
		Facade method for KeyPressed to hide SDL
		*/
		bool KeyPressed(std::string scanCode) const noexcept;
		/**
		Facade method for KeyDown to hide SDL
		*/
		bool KeyDown(std::string scanCode) const noexcept;
		/**
		Facade method for ButtonDown to hide SDL
		*/
		bool ButtonDown(std::string scanCode) const noexcept;
		void Update() noexcept;
		/**
		Checks for any window events and returns the most recent event
		*/
		InputEvent& PollEvents() const noexcept;
		/**
		Returns the current mouse position
		*/
		MousePos GetMousePosition() const noexcept;
		InputFacade() noexcept;
	};
}