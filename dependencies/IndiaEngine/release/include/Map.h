#pragma once
#include "Core.h"
#include "Layer.h"
#include "Tileset.h"
#include <string>
#include <set>

namespace India {
	class India_EXPORT Map {
	public:
		Map(Map&& other) noexcept = default;
		Map& operator=(Map&& other) noexcept = default;
		Map() noexcept;
		~Map() = default;

		void SetWorkingDirectory(const std::string& path) noexcept;
		std::string GetWorkingDirectory() const noexcept;
		bool AddLayer(std::unique_ptr<Layer> layer) noexcept;
		std::vector<std::reference_wrapper<Layer>> GetLayers() const noexcept;
		void AddTileset(const Tileset& tileset) noexcept;
		std::vector<Tileset> GetTilesets() const noexcept;
		void SetRows(int rows) noexcept;
		int GetRows() const noexcept;
		void SetColumns(int columns) noexcept;
		int GetColumns() const noexcept;
		void SetTileSize(int width, int height) noexcept;
		void SetTileSize(const Size& size) noexcept;
		Size GetTileSize() const noexcept;
	private:
		std::vector<std::unique_ptr<Layer>> _layers;
		std::vector<Tileset> _tilesets;
		int _rows;
		int _columns;
		Size _tile_size;
		std::string _working_directory = "";
	};

}
