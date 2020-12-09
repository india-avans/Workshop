#pragma once
#include <string>
#include "Core.h"
#include "Event.h"
#include "Utilities.h"

namespace India {

	struct MousePos {
		int x;
		int y;
	};

	enum InputEventType {
		MOUSE_BUTTON_PRESS,
		MOUSE_BUTTON_RELEASE,
		MOUSE_MOVE,
		USER_QUIT,
		WINDOW_SHOWN,
		WINDOW_HIDDEN,
		WINDOW_EXPOSED,
		WINDOW_MINIMIZED,
		WINDOW_MAXIMIZED,
		WINDOW_RESTORED,
		WINDOW_MOUSE_ENTER,
		WINDOW_MOUSE_LEAVE,
		WINDOW_FOCUSED,
		WINDOW_DEFOCUSED,
		WINDOW_CLOSED,
		WINDOW_TAKE_FOCUS,
		WINDOW_MOVED,
		WINDOW_RESIZED,
		WINDOW_UNKNOWN,
		INPUT_UNKNOWN
	};

	class India_EXPORT InputEvent : public Event<InputEventType>{
	public:
		/**
		 Returns the mouse position (x and y).
		*/
		MousePos GetMousePosition() const noexcept;

		/**
		 Sets the mouse position and converts it to the MousePos struct.
		*/
		void SetMousePosition(int x, int y) noexcept;

		/**
		 Sets the window size.
		*/
		void SetWindowSize(Size size) noexcept;

		/**
		 Returns the window size.
		*/
		Size GetWindowSize() const noexcept;

		void SetType(const InputEventType& type) noexcept override;
		InputEventType GetType() const noexcept override;
	private:
		InputEventType _type;
		MousePos _mouse_pos;
		Size _window_size;
	};
}