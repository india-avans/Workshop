#pragma once
#include "Core.h"
#include "Layer.h"
#include "LevelObject.h"
#include <vector>

namespace India {

	class India_EXPORT TileLayer : public Layer {
	public:

		TileLayer(TileLayer&& other) noexcept = default;
		TileLayer& operator=(TileLayer&& other) noexcept = default;

		TileLayer() noexcept;
		~TileLayer() override;
		void AddTile(std::unique_ptr<LevelObject> tile);
		std::vector<std::reference_wrapper<LevelObject>> GetTiles() noexcept;
	private:
		std::vector<std::unique_ptr<LevelObject>> _tiles;
	};

}
