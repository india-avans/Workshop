#pragma once
#include "InputComponent.h"
#include <memory>

namespace India {
	class InputKeyTranslatorSDL {
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	public:
		InputKeyTranslatorSDL() noexcept;
		~InputKeyTranslatorSDL();
		/**
		Calls to SDL to translate keycode and returns value. Occurs when KeyReleased is called in facade.
		*/
		bool KeyReleased(std::string scancode) const noexcept;
		/**
		Calls to SDL to translate keycode and returns value. Occurs when KeyPressed is called in facade.
		*/
		bool KeyPressed(std::string scancode) const noexcept;
		/**
		Calls to SDL to translate keycode and returns value. Occurs when KeyDown is called in facade.
		*/
		bool KeyDown(std::string scancode) const noexcept;
		/**
		Calls to SDL to translate keycode and returns value. Occurs when ButtonDown is called in facade.
		*/
		bool ButtonDown(std::string scancode) const noexcept;
		/**
		Copies keystate to the memory block pointed to.
		*/
		void Update() noexcept;
	};
}