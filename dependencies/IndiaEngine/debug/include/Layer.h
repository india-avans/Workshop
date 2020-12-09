#pragma once
#include "Core.h"
#include "CustomProperties.h"
#include <string>

namespace India {

	enum LayerType {
		TILE,
		OBJECT,
		NONE
	};

	class India_EXPORT Layer : public CustomProperties {
	public:
		Layer() noexcept;
		Layer(const Layer& other) noexcept;
		Layer(Layer&& other) noexcept = default;
		Layer& operator=(Layer&& other) noexcept = default;

		void SetType(const LayerType& type) noexcept;
		LayerType GetType() const noexcept;
		void SetName(const std::string name) noexcept;
		std::string GetName() const noexcept;
		virtual ~Layer() = 0;
	protected:
		LayerType _type;
		std::string _name;
	};

}
