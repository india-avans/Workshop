#pragma once
#include "Core.h"
#include "Component.h"
#include "Vectors.h"

namespace India {

	class India_EXPORT CameraComponent : public Component {
	public:
		CameraComponent(const CameraComponent& other);

		CameraComponent() noexcept;
		CameraComponent(int width, int height) noexcept;
		~CameraComponent() noexcept override;
		void SetWidth(int width) noexcept;
		int GetWidth() const noexcept;
		void SetHeight(int height) noexcept;
		int GetHeight() const noexcept;
	private:
		int _width;
		int _height;
	};

}