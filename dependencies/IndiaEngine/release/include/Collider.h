#pragma once
#include "Shapes.h"
#include "Vectors.h"

namespace India {
	template<class Shape>
	struct Collider {
		Collider(const Shape& shape) noexcept;
		virtual ~Collider();
		Shape collider;
		/**
		Return true if provided range shape intersects.
		*/
		virtual bool Intersects(const Shape& range) const noexcept = 0;
	};
	template<class Shape>
	Collider<Shape>::Collider(const Shape& shape) noexcept : collider{ shape } {}
	
	template<class Shape>
	inline Collider<Shape>::~Collider()
	{
	}
}