#pragma once
#include "Core.h"
#include "GuiObject.h"

namespace India {

	class India_EXPORT Button : public GuiObject {
	public:
		Button() noexcept;
		Button(int x, int y, int width, int height, const Color& color = { 0,0,0 }) noexcept;
		Button(int x, int y, int width, int height, const std::string& image_path) noexcept;
		~Button() override;
	};

}