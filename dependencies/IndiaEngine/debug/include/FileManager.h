#pragma once
#include "Core.h"
#include "Manager.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace India {

	struct BaseFile {
	public:
		std::string location;
		BaseFile(const std::string& location) noexcept;
	};

	struct India_EXPORT File : public BaseFile {
	public:
		File(const std::string& location) noexcept;
		void AddContents(const std::string& contents) noexcept;
		std::string GetContents() const noexcept;
	private:
		std::string _contents;
	};


	class India_EXPORT FileManager : public Manager
	{
	public:
		FileManager(const std::string& base_directory = "resources/") noexcept;
		bool SaveFile(const File& file) const noexcept;
		File OpenFile(const std::string& location) const noexcept;
	private:
		std::string _base_directory;
	};

}
