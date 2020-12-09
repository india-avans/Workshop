#pragma once
#include "Core.h"
#include "Map.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

#include <string>
#include <memory>

namespace India {

	struct TiledObject {
		float x, y;
		std::string path;
	};

	class India_EXPORT MapLoader {
	public:
		MapLoader(std::string base_directory = "resources/") noexcept;
		~MapLoader();
		std::unique_ptr<Map> LoadMap(const std::string& path);
	private:
		std::string _base_directory;
		struct impl;
		std::unique_ptr<impl> pimpl;
	};

}
