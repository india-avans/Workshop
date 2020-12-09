#pragma once
#include "Objects.h"
#include <iostream>

namespace Collision {
	enum class Handlers {
		RevertDirection, Stop
	};
	/**
	Reposition the target to the subject's corresponding location for the specified direction of the collision.
	*for example: target gets repositioned above the subject when the collision is in a downward direction.
	*/
	void RepositionTarget(India::Object& target, India::Object& subject, India::Direction direction);
	/**
	Enables or disables velocity in the specified direction for the specified target.
	*/
	void ToggleVelocityDirection(India::Object& target, India::Direction direction, bool enabled);
	/**
	Enables or disabled gravity for the specified target.
	*/
	void ToggleGravity(India::Object& target, bool enabled);
	/**
	Updates the target's velocity for a collision in the specified directory with the specified handler.
	*/
	void UpdateVelocity(India::Object& target, India::Direction direction, Collision::Handlers handler);
}