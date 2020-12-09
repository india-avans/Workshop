#pragma once
#include "Core.h"
#include "Color.h"
#include <string>
#include <functional>
#include <sstream>
#include <istream>

namespace India {

	enum class India_EXPORT RenderType {
		Screen, World, NoResize
	};

	enum class India_EXPORT FlipType {
		None, Horizontal, Vertical
	};

	namespace Utilities {

		/**
		 Prints the type and message of the exceptions and the executes the provided callback.
		 *the callback is set to exit the application by default.
		*/
		India_EXPORT void HandleException(const std::exception& exception, const std::function<void()> callback = [] {}) noexcept;
		/**
		Checks if a string ends with the suffix.
		*/
		India_EXPORT bool EndsWith(const std::string& str, const std::string& suffix) noexcept;
		/**
		Prints a message.
		*/
		India_EXPORT void PrintMessage(const std::string& message) noexcept;
		/**
		Prints an error message.
		*/
		India_EXPORT void PrintErrorMessage(const std::string& error_message) noexcept;
		/**
		 Makes the current thread sleep for the specified amount of milliseconds.
		*/
		India_EXPORT void Sleep(int ms) noexcept;
		/**
		 Returns a Color struct from a hex string
		*/
		Color StringToColor(const std::string& hex_value) noexcept;
		/**
		 Splits a string by the specified delimiter
		*/
		India_EXPORT std::vector<std::string> Split(const std::string& s, const std::string& delimiter);
		template<typename T>
		/**
		 Extracts the raw class name from a reference without namespace (India::Object would become 'Object')
		*/
		std::string GetClassName(T& object) {
			std::string str = typeid(object).name();
			std::size_t last = 0;
			for (int i = 0; i < str.size(); ++i) {
				auto c = str[i];
				if (c == ' ') {
					last = i;
					break;
				}
			}
			str = str.substr(last, str.size());
			last = 0;
			for (int i = 0; i < str.size(); ++i) {
				auto c = str[i];
				if (c == ':') {
					last = i;
				}
			}
			return str.substr(last + 1, str.size());
		}

	}


	struct Size {
		int width, height;
	};

	enum class Axis {
		Horizontal, Vertical
	};

	enum class Direction {
		Up, Down, Left, Right, Any
	};
}
