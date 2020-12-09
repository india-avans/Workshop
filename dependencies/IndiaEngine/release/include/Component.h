#pragma once
#include "Core.h"

namespace India {

	enum class India_EXPORT ComponentState {
		Uninitialized,
		Initialized,
		Active,
		Inactive,
	};

	class India_EXPORT Component {
	public:
		Component(const Component& other);
		Component() noexcept;
		/**
		Returns state of this component
		*/
		ComponentState GetState() const noexcept;

		/**
		Returns true if state equals the component's state.
		*/
		bool IsState(ComponentState state) const noexcept;
		/**
		Sets state of this component to parameter value.
		*/
		void SetState(const ComponentState& state) noexcept;

		virtual ~Component() = 0;
	private:
		ComponentState _state;
	};

}