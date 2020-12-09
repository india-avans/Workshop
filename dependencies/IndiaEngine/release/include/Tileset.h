#pragma once
#include "Core.h"
#include "Utilities.h"
#include <string>

namespace India {
	class India_EXPORT Tileset {
	public:
		void SetFirstGid(int first_gid) noexcept;
		int GetFirstGid() const noexcept;
		void SetImageSize(const Size& size) noexcept;
		void SetImageSize(int width, int height) noexcept;
		Size GetImageSize() const noexcept;
		void SetPath(const std::string& path) noexcept;
		std::string GetPath() const noexcept;
		void SetTileCount(int tile_count) noexcept;
		int GetTileCount() const noexcept;
	private:
		int _first_gid;
		std::string _path;
		Size _image_size;
		int _tile_count = 0;
	};

}
