#pragma once
#include "Core.h"
#include "System.h"
#include <ObjectQuadtree.h>
#include <DrawingFacade.h>

namespace India {

	class India_EXPORT CollisionSystem : public System {
	public:
		CollisionSystem() noexcept;
		~CollisionSystem() = default;
		/**
		Calculates a quadtree for all stationary collidable objects once, recalculates when collection of stationary collidable objects changes.
		Calculates a quadtree for all moving collidable objects every iteration.
		For every moving collidable object, queries objects near its next position, then checks every nearby object for collision and adds colliding object the to subject's CollisionComponent.
		Each CollisionComponent then handles the collisions in each direction.
		*/
		void Update(UpdateParameters& params) noexcept override;
	private:
		std::unique_ptr<ObjectQuadtree> _static_quad_tree;
		int _active_scene_index;
	};
}