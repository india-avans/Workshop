#include "CollisionHandlers.h"

void Collision::RepositionTarget(India::Object& target, India::Object& subject, India::Direction direction)
{
	if (subject.GetIndex() != target.GetIndex()
		&& target.HasComponent<India::CollisionComponent>() && subject.HasComponent<India::CollisionComponent>()) {
		auto& target_transform = target.GetComponent<India::TransformComponent>();
		auto target_collider_bounds = target.GetComponent<India::CollisionComponent>().GetBounds();
		auto target_collider = target.GetComponent<India::CollisionComponent>().GetCollider().collider;
		auto subject_transform = subject.GetComponent<India::TransformComponent>();
		auto subject_collider = subject.GetComponent<India::CollisionComponent>().GetCollider().collider;
		switch (direction) {
		case India::Direction::Up:
			target_transform.SetY(subject_collider.BottomLeft().y - target_collider_bounds.y);
			break;
		case India::Direction::Down:
			target_transform.SetY(subject_collider.TopRight().y - target_collider_bounds.y - target_collider.height);
			break;
		case India::Direction::Left:
			target_transform.SetX(subject_collider.TopRight().x - target_collider_bounds.x);
			break;
		case India::Direction::Right:
			target_transform.SetX(subject_collider.BottomLeft().x - target_collider_bounds.x - target_collider.width);
			break;
		}
	}
}

void Collision::ToggleVelocityDirection(India::Object& target, India::Direction direction, bool enabled)
{
	if (target.HasComponent<India::VelocityComponent>()) {
		target.GetComponent<India::VelocityComponent>().SetDirectionState(direction, enabled);
	}
}

void Collision::ToggleGravity(India::Object& target, bool enabled)
{
	if (target.HasComponent<India::PhysicsComponent>()) {
		target.GetComponent<India::PhysicsComponent>().SetState(enabled ? India::ComponentState::Active : India::ComponentState::Inactive);
	}
}

void Collision::UpdateVelocity(India::Object& target, India::Direction direction, Collision::Handlers handler)
{
	if (target.HasComponent<India::VelocityComponent>()) {
		auto& target_velocity_component = target.GetComponent<India::VelocityComponent>();
		auto target_axis = India::Axis::Horizontal;

		switch (direction) {
		case India::Direction::Up:
		case India::Direction::Down:
			target_axis = India::Axis::Vertical;
			break;
		case India::Direction::Left:
		case India::Direction::Right:
			target_axis = India::Axis::Horizontal;
			break;
		}

		float target_velocity = target_axis == India::Axis::Horizontal ? target_velocity_component.GetX() : target_axis == India::Axis::Vertical ? target_velocity_component.GetY() : 0;

		switch (handler) {
		case Collision::Handlers::RevertDirection:
			if (handler == Collision::Handlers::RevertDirection) {
				switch (direction) {
				case India::Direction::Up:
					if (target.HasComponent<India::PhysicsComponent>()) {
						target_velocity = 0;
					}
					break;
				case India::Direction::Down:
					if (target.HasComponent<India::PhysicsComponent>()) {
						auto mass = target.GetComponent<India::PhysicsComponent>().GetMass() * 2;
						target_velocity = std::abs(mass > target_velocity ? mass : target_velocity) * -1;
					}
					break;
				case India::Direction::Left:
				case India::Direction::Right:
					target_velocity = target_velocity_component.GetX() * -1;
					break;
				}
			}
			break;
		case Collision::Handlers::Stop:
			target_velocity = 0;
			break;
		}
		switch (target_axis) {
		case India::Axis::Horizontal:
			target_velocity_component.SetX(target_velocity);
			break;
		case India::Axis::Vertical:
			target_velocity_component.SetY(target_velocity);
			break;
		}
	}
}


