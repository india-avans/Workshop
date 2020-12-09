#pragma once
#include "Core.h"
#include <string>

namespace India {

	struct India_EXPORT Text {
	public:
		Text() : Text("", "") {}
		Text(std::string text, std::string font, int font_size = 14) : font(font), font_size(font_size), text(text) {}
		std::string font;
		int font_size;
		std::string text;
	};
}