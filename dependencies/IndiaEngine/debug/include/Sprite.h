#pragma once
#include "Vectors.h"
#include "Shapes.h"
#include "Utilities.h"
#include <string>

namespace India {


	
	struct India_EXPORT Sprite {
	public:
		Sprite(
			std::string path = "", Rectangle src_rect = { -1, -1, -1, -1 }, FlipType flip_type = FlipType::None
		) noexcept {
			this->path = path;
			this->src_rect = src_rect;
			this->flip_type = flip_type;
		};
		std::string path;
		Rectangle src_rect;
		FlipType flip_type;
	};

}