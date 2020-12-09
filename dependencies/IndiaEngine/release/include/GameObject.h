#pragma once
#include "Core.h"
#include "Object.h"
#include "Components.h"
#include "Sprite.h"

#include <map>
#include <string>

namespace India {

	struct India_EXPORT GameObjectData {
	public:
		GameObjectData(
			float x, float y,
			float width, float height,
			int animation_delay,
			std::map<std::string, std::vector<Sprite>> sprites,
			std::string active_sprite_key
		) noexcept;
		float x;
		float y;
		float width;
		float height;
		int animation_delay;
		std::map<std::string, std::vector<Sprite>> sprites;
		std::string active_sprite_key;
	};

	class India_EXPORT  GameObject : public Object {
	public:
		GameObject(const GameObject& other);
		GameObject(float x, float y, float width, float height) noexcept;
		GameObject(const GameObjectData& data) noexcept;
		/**
		 Draws a gameobject on the window.
		*/
		virtual void Draw(const Graphics2D& g) const override;
		virtual ~GameObject() = 0;
	};

}
