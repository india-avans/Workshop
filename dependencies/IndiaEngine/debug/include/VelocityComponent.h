#pragma once
#include "Core.h"
#include "Component.h"

#include <map>
#include <Utilities.h>

namespace India {

	class India_EXPORT VelocityComponent : public Component {
	public:
		VelocityComponent(const VelocityComponent& other);

		VelocityComponent() noexcept;
		VelocityComponent(float velocity_x, float velocity_y) noexcept;
		~VelocityComponent() override;
		/**
		Set X-velocity of this component accordingly to parameter value.
		*/
		void SetX(float x) noexcept;
		/**
		Returns X-velocity property of this component.
		*/
		float GetX() const noexcept;

		/**
		Set Y-velocity of this component accordingly to parameter value.
		*/
		void SetY(float y) noexcept;
		/**
		Returns Y-velocity property of this component.
		*/
		float GetY() const noexcept;

		/**
		Set decay x of this component accordingly to parameter value.
		*/
		void SetDecayX(float decay) noexcept;
		/**
		Returns decay y property of this component.
		*/
		float GetDecayX() const noexcept;
		/**
		Set decay y of this component accordingly to parameter value.
		*/
		void SetDecayY(float decay) noexcept;
		/**
		Returns decay y property of this component.
		*/
		float GetDecayY() const noexcept;
		/**
		Sets the state in the specified direction.
		*/
		void SetDirectionState(Direction direction, bool enabled) noexcept;
		/**
		Returns whether the velocity in the specified direction is enabled or not.
		*/
		bool GetDirectionState(Direction direction) const noexcept;

		/**
		Returns the current direction based on the velocity for the specified axis.
		*/
		Direction GetCurrentDirection(Axis axis) const noexcept;
	private:
		std::map<Direction, bool> _direction_states;
		float _velocity_x;
		float _velocity_y;
		float _decay_x;
		float _decay_y;
	};
}