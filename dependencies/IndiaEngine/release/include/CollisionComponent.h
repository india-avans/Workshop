#pragma once
#include "Component.h"
#include "Object.h"
#include "BoxCollider.h"
#include "Utilities.h"

#include <map>
#include <functional>

namespace India {

	class India_EXPORT CollisionComponent : public Component {
	private:
		std::map<Direction, std::vector<Object*>> _collisions;
		std::map<Direction, std::pair<std::function<void(Object&)>, std::function<void()>>> _collision_handlers;
		BoxCollider _box_collider;
		bool _trigger;
		Rectangle _bounds;
	public:
		CollisionComponent() noexcept;
		CollisionComponent(Rectangle bounds, std::map<Direction, std::pair<std::function<void(Object&)>, std::function<void()>>> collision_handlers = {}) noexcept;
		~CollisionComponent() override;
		/**
		Handles collision in the specified direction;
		Calls the on collision function if there's a collision in the direction.
		Calls the second function otherwise.
		*/
		void HandleCollisions(const Direction& direction) noexcept;
		/**
		Handles collisions in all directions;
		*/
		void HandleAllCollisions() noexcept;
		/**
		Adds a collision in the specified direction along with the subject with which the object collided.
		*/
		void AddCollision(const Direction& direction, Object& subject);
		/**
		Removes a collision in the specified direction if there's a collision in the specified direction.
		*/
		bool RemoveCollisions(const Direction& direction) noexcept;
		/**
		Returns true when there's a collision in the specified direction.
		*/
		template<class ObjectType = Object>
		bool Collides(const Direction& direction) noexcept;
		/**
		Removes any existing collisions.
		*/
		void ClearCollisions() noexcept;
		/**
		Returns the colliding object in the specified direction if there's a collision in the specified direction.
		*/
		template<class ObjectType = Object>
		ObjectType& GetCollisionSubject(const Direction& direction, int index) {
			if (Collides(direction)) {
				for (auto subject : _collisions[direction]) {
					if (subject != nullptr
						&& dynamic_cast<ObjectType*>(subject)
						&& subject->GetIndex() == index) {
						return dynamic_cast<ObjectType&>(*subject);
					}
				}
			}
			throw CollisionComponentException("Tried getting non-existent collision subject");
		};
		template<class ObjectType = Object>
		std::vector<std::reference_wrapper<ObjectType>> GetCollisionSubjects(const Direction& direction) {
			std::vector<std::reference_wrapper<ObjectType>> subjects;
			for (auto subject : _collisions[direction]) {
				if (dynamic_cast<ObjectType*>(subject))
					subjects.push_back(dynamic_cast<ObjectType&>(*subject));
			}
			return subjects;
		};
		/**
		Returns a rectangle representing the hitbox of the object.
		*/
		BoxCollider GetCollider() const noexcept;
		/**
		Sets the hitbox of the object
		*/
		void SetCollider(const BoxCollider& box_collider) noexcept;
		/**
		Returns the bounds of this component.
		The bounds are the dimensions of the hitbox relative to the object's position.
		*/
		Rectangle GetBounds() const noexcept;
		/**
		Sets the relative bounds of the hitbox.
		*/
		void SetBounds(const Rectangle& bounds) noexcept;
		/**
		Determines whether the hitbox is a trigger or not.
		*/
		void SetTrigger(bool trigger) noexcept;
		/**
		Returns true if this is a trigger.
		A trigger is a hitbox which is not solid.
		Example: a door will have a trigger hitbox to detect when something is in front of the door.
		*/
		bool IsTrigger() const noexcept;
	};

	template<class ObjectType>
	inline bool CollisionComponent::Collides(const Direction& direction) noexcept
	{
		for (auto collision : _collisions[direction]) {
			if (dynamic_cast<ObjectType*>(collision)) {
				return true;
			}
		}
		return false;
	}

}