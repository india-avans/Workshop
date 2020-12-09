#pragma once
#include "Core.h"
#include "LevelProperty.h"
#include <unordered_map>
#include <string>

namespace India {

	class India_EXPORT CustomProperties {
	public:
		CustomProperties(const CustomProperties& other);
		CustomProperties(CustomProperties&& other) noexcept = default;
		CustomProperties& operator=(CustomProperties&& other) noexcept = default;
		CustomProperties() noexcept;
		virtual ~CustomProperties() = 0;
		void AddProperty(const LevelProperty& property) noexcept;
		std::unordered_map<std::string, LevelProperty> GetProperties() const noexcept;
		LevelProperty GetProperty(const std::string& name) const;
		bool HasProperty(const std::string& name) const noexcept;
	private:
		std::unordered_map<std::string, LevelProperty> _properties;
	};

}