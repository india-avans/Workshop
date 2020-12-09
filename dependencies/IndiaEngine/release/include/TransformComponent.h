#pragma once
#include "Core.h"
#include "Component.h"
#include "Vectors.h"
#include "Shapes.h"

namespace India {

	class India_EXPORT TransformComponent : public Component {
	public:
		TransformComponent(const TransformComponent& other);

		TransformComponent() noexcept;
		TransformComponent(float x, float y, float width, float height) noexcept;
		~TransformComponent() override;

		/**
		Set X location of this component accordingly to provided value
		*/
		void SetX(float x) noexcept;
		/**
		Set X location of this component accordingly to provided value, without a bounds check.
		*/
		void ForceSetX(float x) noexcept;
		/**
		Returns X location of this component
		*/
		float GetX() const noexcept;
		/**
		Set Y location of this component accordingly to provided value
		*/
		void SetY(float y) noexcept;
		/**
		Set Y location of this component accordingly to provided value, without a bounds check.
		*/
		void ForceSetY(float y) noexcept;
		/**
		Returns Y location of this component
		*/
		float GetY() const noexcept;
		/**
		Returns X AND Y
		*/
		Vector2 GetLocation() const noexcept;

		/**
		Sets width of this component accordingly to value.
		*/
		void SetWidth(float width) noexcept;
		/**
		Returns width of this component
		*/
		float GetWidth() const noexcept;
		/**
		Sets height  of this component accordingly to value.
		*/
		void SetHeight(float height) noexcept;
		/**
		Returns height of this component
		*/
		float GetHeight() const noexcept;

		/**
		Sets the bounds of the X and Y between 0 and the specified values
		*/
		void SetBounds(float x, float y) noexcept;

		/**
		Returns the current bounds for the location's x and y.
		*/
		Vector2 GetBounds() const noexcept;

		/**
		Returns the rectangle of the object's bounds.
		*/
		Rectangle GetRectangle() const noexcept;

	private:
		Vector2 _location;
		Vector2 _bounds;
		float _width;
		float _height;
	};

}