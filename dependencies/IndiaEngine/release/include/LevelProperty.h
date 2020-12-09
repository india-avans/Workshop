#pragma once
#include "Core.h"
#include "Color.h"
#include <string>
#include <cassert>

namespace India {

	enum class PropertyType
	{
		Boolean,
		Float,
		Int,
		String,
		Color,
		File,
		Object
	};

	class India_EXPORT LevelProperty {
	public:

		LevelProperty();
		~LevelProperty() = default;

		void SetType(const PropertyType& type) noexcept;
		PropertyType GetType() const noexcept;
		void SetName(const std::string& name) noexcept;
		std::string GetName() const noexcept;

		void SetBoolValue(bool value) noexcept;
		void SetFloatValue(float value) noexcept;
		void SetIntValue(int value) noexcept;
		void SetStringValue(const std::string& value) noexcept;
		void SetColorValue(const Color& color) noexcept;

		bool GetBoolValue() const noexcept;
		float GetFloatValue() const noexcept;
		int GetIntValue() const noexcept;
		std::string GetStringValue() const noexcept;
		Color GetColorValue() const noexcept;
		std::string GetFileValue() const noexcept;
		int GetObjectValue() const noexcept;


	private:
		union
		{
			bool _bool_value;
			float _float_value;
			int _int_value;
		};
		std::string _string_value;
		std::string _name;
		Color _color_value;
		PropertyType _type;
	};

}
