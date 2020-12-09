#pragma once
#include "BuildSettingsStruct.h"
#include <cstdio>
#include <string>
#include <fstream>
namespace India {
	class BuildSettings {
	private:
	public:
		/**
		Save the provided values from the BuildSettingsStruct to the provided path.
		*/
		void Save(std::string path, BuildSettingsStruct build_settings_struct) noexcept;
		BuildSettingsStruct Load(std::string path) const noexcept;
		bool Exists(const std::string& name) const noexcept;
	};
}