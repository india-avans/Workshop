#pragma once
#include "Core.h"
#include "Vectors.h"
#include "Utilities.h"

namespace India {

	struct India_EXPORT Shape {
	public:
		float x;
		float y;
	};

	struct India_EXPORT Rectangle : public Shape {
	public:
		Rectangle();
		Rectangle(float x, float y, float width, float height);
		float width;
		float height;
		RenderType render_type = RenderType::World;

		/**
	    Returns the top right point of the rectangle.
	    */
		Vector2 TopRight() const noexcept;
		/**
		Returns the bottom left point of the rectangle.
		*/
		Vector2 BottomLeft() const noexcept;
	};

}