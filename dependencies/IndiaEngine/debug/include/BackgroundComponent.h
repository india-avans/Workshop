#pragma once
#include "Component.h"
#include "Color.h"
#include <string>

namespace India {

	class India_EXPORT BackgroundComponent : public Component {
	private:
		Color _color;
		std::string _image_path = "";
	public:
		BackgroundComponent(const BackgroundComponent& other);

		BackgroundComponent(Color color) noexcept;
		BackgroundComponent(std::string image_path) noexcept;
		BackgroundComponent() noexcept;
		/**
		Returns color of this BackgroundComponent
		*/
		Color GetColor() const noexcept;
		/**
		Sets color of this backgroundcomponent accordingly to value in parameter
		*/
		void SetColor(const Color& color) noexcept;
		/**
		Returns image path
		*/
		std::string GetImagePath() const noexcept;
		/**
		Sets image path accordingly to value in parameter
		*/
		void SetImagePath(const std::string& image_path) noexcept;

	};
}
