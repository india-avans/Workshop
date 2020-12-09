#pragma once
#include "Core.h"
#include "Object.h"
#include "Components.h"
#include "Sprite.h"
#include "CustomProperties.h"
#include <string>

namespace India {

	struct LevelObjectData {
		float x, y, width, height;
		Sprite sprite;
	};

	class India_EXPORT LevelObject : public Object, public CustomProperties {
	public:
		LevelObject(const LevelObject& other);

		LevelObject() noexcept;
		LevelObject(const LevelObjectData& data) noexcept;
		~LevelObject() = default;
		void SetName(const std::string name) noexcept;
		std::string GetName() const noexcept;
		void SetType(const std::string name) noexcept;
		std::string GetType() const noexcept;
		std::vector<std::string> GetArgs();
		virtual void Draw(const Graphics2D&) const noexcept override;
	private:
		std::string _name;
		std::string _type;
	};

}
