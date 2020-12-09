#pragma once
#include "Core.h"
#include "Collider.h"

namespace India {

	struct India_EXPORT BoxCollider : public Collider<Rectangle> {
		BoxCollider() noexcept;
		BoxCollider(const Rectangle& rectangle) noexcept;
		/**
		Return true if provided range rectangle intersects.
		*/
		bool Intersects(const Rectangle& range) const noexcept override;
	};

}