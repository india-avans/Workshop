#pragma once
#include "Core.h"
#include "LevelObject.h"
#include <string>

namespace India {

	class India_EXPORT LevelText : public LevelObject {
	public:
		LevelText(const LevelText& other);
		LevelText(const LevelObjectData& data, Text& text, Color color = {0,0,0}) noexcept;
		void Draw(const Graphics2D& g) const noexcept override;
	private:
		Text _text;
		Color _color;
	};

}
